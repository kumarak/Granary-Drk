from Queue import Queue
from threading import Thread, Event
import time

from drpy.observer import Subject

class Future(object):
    def __init__(self, fn, *args, **kwargs):
        self.queue = Queue()
        self.fn = fn
        self.args = args
        self.kwargs = kwargs
        self.start_subject = Subject()
        self.stop_subject = Subject()

    def add_start_observer(self, observer):
        self.start_subject.add_observer(observer)
    
    def add_stop_observer(self, observer):
        self.stop_subject.add_observer(observer)

    def deliver_exception(self, exception):
        self.queue.put((False, exception))

    def fn_main(self):
        try:
            self.queue.put((True, self.fn(*self.args, **self.kwargs)))
        except Exception as e:
            self.queue.put((False, e))

    def run(self):
        fn_thread = Thread(target=self.fn_main)
        self.start_subject.notify(self)
        fn_thread.start()
        result = self.queue.get()
        self.stop_subject.notify(self)
        if result[0]:
            return result[1]
        else:
            # TODO(peter): kill self.fn_thread? Killing it using some posix
            # interface can make python buggy. Not killing it might make screw
            # with future tests.
            raise result[1]

class FutureRunner(object):
    def __init__(self, *monitors):
        self.monitors = monitors

    def run(self, fn, *args, **kwargs):
        future = Future(fn, *args, **kwargs)
        for monitor in self.monitors:
            future.add_start_observer(monitor.future_start)
        return future.run()

class FutureMonitor(object):
    def future_start(self, future):
        pass

class TimeoutException(Exception):
    pass

class TimeoutObserver(object):
    def __init__(self, timeout, future):
        self.future = future
        self.future.add_stop_observer(self.future_stop)
        self.event = Event()
        self.timeout = timeout
        thread = Thread(target=self.timeout_main)
        thread.start()

    def future_stop(self, future):
        self.event.set()

    def timeout_main(self):
        self.event.wait(self.timeout)
        if not self.event.is_set():
            self.future.deliver_exception(TimeoutException())

class TimeoutMonitor(FutureMonitor):
    def __init__(self, timeout):
        FutureMonitor.__init__(self)
        self.timeout = timeout

    def future_start(self, future):
        TimeoutObserver(self.timeout, future)
