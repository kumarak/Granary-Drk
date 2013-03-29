import unittest
from observer import Subject

from drpy.debugger import GDBDebugger, DebuggerExitMonitor, DebuggerExitException
from drpy.future import FutureRunner
from threading import Semaphore

class MockGDBStub(object):
    def __init__(self):
        self.event_subject = Subject()
        self.running = True

    def add_event_observer(self, observer):
        self.event_subject.add_observer(observer)

    def remove_exit_observer(self, observer):
        self.event_subject.remove_observer(observer)

    def execute(self, command):
        if command == 'continue':
            self.running = True

    def pause(self):
        assert self.running
        self.running = False
        self.event_subject.notify()

    def execute_sync(self, command):
        self.execute(command)

    def simulate_exit(self):
        assert self.running
        self.running = False
        self.event_subject.notify()

class Counter(object):
    def __init__(self):
        self.value = 0

    def increment(self):
        self.value += 1

class DebuggerTestCase(unittest.TestCase):
    def test_basics(self):
        mock_stub = MockGDBStub()
        debugger = GDBDebugger(mock_stub)
        debugger.pause()
        debugger.resume()

    def test_exits(self):
        mock_stub = MockGDBStub()
        debugger = GDBDebugger(mock_stub)
        num_exits = Counter()
        debugger.add_exit_observer(num_exits.increment)

        debugger.pause()
        self.assertEqual(1, num_exits.value)
        debugger.resume()

        mock_stub.simulate_exit()
        self.assertEqual(2, num_exits.value)
        debugger.resume()

        debugger.add_exit_observer(num_exits.increment)
        mock_stub.simulate_exit()
        self.assertEqual(4, num_exits.value)
        debugger.resume()

        debugger.remove_exit_observer(num_exits.increment)
        mock_stub.simulate_exit()
        self.assertEqual(5, num_exits.value)
        debugger.resume()

        debugger.remove_exit_observer(num_exits.increment)
        mock_stub.simulate_exit()
        self.assertEqual(5, num_exits.value)
        debugger.resume()

class DebuggerExitMonitorTestCase(unittest.TestCase):
    def test_exit_after_start(self):
        mock_stub = MockGDBStub()
        debugger = GDBDebugger(mock_stub)
        runner = FutureRunner(DebuggerExitMonitor(debugger))

        def simulate_exit_and_block(mock_stub, semaphore):
            mock_stub.simulate_exit()
            semaphore.acquire()

        semaphore = Semaphore(0)
        self.assertRaises(DebuggerExitException, runner.run,
                          simulate_exit_and_block, mock_stub, semaphore)
        semaphore.release()
