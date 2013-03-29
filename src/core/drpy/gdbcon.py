from multiprocessing import Process, JoinableQueue, Queue
from threading import Thread
import errno
import gdb
import logging
import os
import signal
import time

from drpy.observer import Subject

class Event(object):
    EXIT = 'EXIT'

class Command(object):
    RETURN_TO_INTERPRETER = 'RETURN_TO_INTERPRETER'
    INTERRUPT = 'INTERRUPT'

    def __init__(self, command, queue_output=False, is_meta=False):
        self.command = command
        self.queue_output = queue_output
        self.is_meta = is_meta

class GDBStubClient(object):
    
    def __init__(self, command_queue, response_queue, event_queue, server_pid):
        self.logger = logging.getLogger('GDBStubClient')

        self.command_queue = command_queue
        self.response_queue = response_queue
        self.event_queue = event_queue
        self.server_pid = server_pid

        self.quitting = False
        
        self.event_subject = Subject()
        self.event_thread = Thread(target=self.event_thread_main)
        self.event_thread.start()

    def event_thread_main(self):
        # After RETURN_TO_INTERPRETER has been processed, we are
        # disconnected from GDB's event generators, so the size of the event
        # queue is monotonically decreasing. The last event is a fake one
        # that we queue so queue.get returns.
        while True:
            event = self.event_queue.get()
            if self.quitting and self.event_queue.empty():
                break
            print event
            self.event_subject.notify(event)

    def add_event_observer(self, observer):
        self.event_subject.add_observer(observer)

    def execute(self, command):
        self.logger.debug('execute ' + command)
        self.command_queue.put(Command(command))

    def execute_sync(self, command):
        self.logger.debug('execute_sync ' + command)
        self.command_queue.put(Command(command, queue_output=True))
        self.command_queue.join()
        return self.response_queue.get()

    def pause(self):
        self.logger.debug('pause')
        self.command_queue.put(Command(Command.INTERRUPT, is_meta=True))
        os.kill(self.server_pid, signal.SIGINT)
        self.logger.debug('pause waiting for command queue to empty')
        self.command_queue.join()
        self.logger.debug('pause command queue empty')

    def abort(self):
        self.command_queue.put(
            Command(Command.RETURN_TO_INTERPRETER, is_meta=True))

    def return_to_interpreter(self):
        self.logger.debug('returning to GDB command interpreter')
        self.command_queue.put(
            Command(Command.RETURN_TO_INTERPRETER, is_meta=True))
        self.command_queue.join()
        self.quitting = True
        self.event_queue.put(None)
        self.event_thread.join()

class GDBStubServer(object):

    def __init__(self, command_queue, response_queue, event_queue):
        self.command_queue = command_queue
        self.response_queue = response_queue
        self.event_queue = event_queue
        # Not supported by GDB 7.1 :(
        #gdb.events.exited.connect(self.event_handler)
        #gdb.events.cont.connect(self.event_handler)
        #gdb.events.stop.connect(self.event_handler)

    def event_handler(self, event):
        #TODO(peter): queue the actual events.
        self.event_queue.put(1)

    def is_run_command(self, cmd):
        return 'run'.find(cmd) == 0 or\
               ('continue'.find(cmd) == 0 and len(cmd) >= len('cont')) or\
               cmd == 'c'

    def run(self):
        while True:
            command = self.command_queue.get()
            if command.is_meta:
                assert not command.queue_output
                if command.command == Command.RETURN_TO_INTERPRETER:
                    # Not supported by GDB 7.1 :(
                    #gdb.events.exited.disconnect(self.event_handler)
                    #gdb.events.cont.disconnect(self.event_handler)
                    #gdb.events.stop.disconnect(self.event_handler)
                    self.command_queue.task_done()
                    break
                elif command.command == Command.INTERRUPT:
                    pass
                else:
                    assert False
            else:
                # In GDB 7.3, use
                # response = gdb.execute(command.command, True,from_tty=True,
                #                        to_string=command.queue_output)
                response = gdb.execute(command.command, True)
                if self.is_run_command(command.command):
                    self.event_queue.put(Event.EXIT)
                if command.queue_output:
                    self.response_queue.put(response)
            self.command_queue.task_done()

def start_client(commands, responses, events, server_pid, client_main, args):
    gdb_stub = GDBStubClient(commands, responses, events, server_pid)
    try:
        client_main(gdb_stub, *args)
    except Exception, e:
        logger = logging.getLogger('GDBStubClient')
        logger.error('Unhandled exception in client_main. Pausing the ' +\
                     'debugger before aborting.')
        gdb_stub.pause()
        raise
    finally:
        gdb_stub.return_to_interpreter()

def start_server(client_main, *args):
    commands = JoinableQueue()
    responses = Queue()
    events = Queue()
    server = GDBStubServer(commands, responses, events)
    client_args = (commands, responses, events, os.getpid(),client_main, args)
    client = Process(target=start_client, args=client_args)
    client.start()
    server.run()
    client.join(5)
    if client.is_alive():
        print 'Warning: GDBStubClient is still alive 5s after ' +\
              'GDBStubServer.run() returned. This is probably an error. ' +\
              'Did you call GDBStubClient.return_to_interpreter() twice ' +\
              'or call GDBStubClient.execute_sync() after calling ' +\
              'return_to_interpreter? Blocking until GDBStubClient dies. ' +\
              'You can kill it manually (kill -9 %d).' % (client.pid)
        client.join()
