from StringIO import StringIO
from drpy.future import FutureMonitor
from drpy.observer import Subject

class GDBDebugger(object):

    def __init__(self, gdb_stub):
        self.gdb_stub = gdb_stub
        self.gdb_stub.execute_sync('set breakpoint pending on')
        self.exit_subject = Subject()
        gdb_stub.add_event_observer(self.exit_subject.notify)

    def add_symbol_file(self, symbol_file, sections):
        out = StringIO()
        out.write('add-symbol-file /home/pag/Code/drk/src/core/%s ' % (symbol_file))
        out.write(sections['.text'])
        del sections['.text']
        for section in sections.iteritems():
            out.write(' -s %s %s' % (section[0], section[1]))
        out.write(' -readnow')
        self.gdb_stub.execute_sync(out.getvalue())

    def set_main_symbol_file(self, symbol_file):
        self.gdb_stub.execute_sync('file %s' % symbol_file)

    def add_breakpoint(self, symbol):
        self.gdb_stub.execute_sync('break %s' % symbol)

    def clear_symbols(self):
        self.gdb_stub.execute_sync('file')

    def clear_breakpoints(self):
        self.gdb_stub.execute('delete')

    def attach_tcp(self, host, port):
        self.gdb_stub.execute_sync('target remote %s:%s' % (host, str(port)))

    def detach(self):
        self.clear_breakpoints()
        self.clear_symbols()
        self.gdb_stub.execute_sync('detach')

    def add_exit_observer(self, observer):
        self.exit_subject.add_observer(observer)

    def remove_exit_observer(self, observer):
        self.exit_subject.remove_observer(observer)

    def pause(self):
        self.gdb_stub.pause()

    def resume(self):
        self.gdb_stub.execute('continue')

class DebuggerExitException(Exception):
    pass

class DebuggerExitObserver(object):
    def __init__(self, debugger, future):
        debugger.add_exit_observer(self.exit)
        self.future = future
        self.debugger = debugger
    
    def exit(self):
        self.debugger.remove_exit_observer(self.exit)
        self.future.deliver_exception(DebuggerExitException())
        
class DebuggerExitMonitor(FutureMonitor):
    '''Needs to be used with a TimeoutMonitor because of the race between the
    debugger exiting and attaching to the debugger.'''
    def __init__(self, debugger):
        FutureMonitor.__init__(self)
        self.debugger = debugger

    def future_start(self, future):
        DebuggerExitObserver(self.debugger, future)
