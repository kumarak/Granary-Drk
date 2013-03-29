import unittest
import time

from future import Future, FutureRunner, TimeoutException, TimeoutMonitor
from threading import Semaphore

def identity(x):
    return x

def do_raise(e):
    raise e

class FutureTestCase(unittest.TestCase):
    def test_simple(self):
        future = Future(identity, x=5)
        self.assertEqual(5, future.run())

    def test_exception(self):
        class MyException(Exception) : pass
        future = Future(do_raise, MyException())
        self.assertRaises(MyException, future.run)

    def test_enough_time(self):
        runner = FutureRunner(TimeoutMonitor(1))
        # Use the same runner twice.
        self.assertEqual(5, runner.run(identity, x=5))
        self.assertEqual(5, runner.run(identity, x=5))

    def test_timeout(self):
        runner = FutureRunner(TimeoutMonitor(0.1))
        semaphore = Semaphore(0)
        # Simple timeout test.
        self.assertRaises(TimeoutException, runner.run, semaphore.acquire)
        semaphore.release()
        # Use the runner twice concurrently.
        self.assertRaises(TimeoutException, runner.run, semaphore.acquire)
        self.assertRaises(TimeoutException, runner.run, semaphore.acquire)
        semaphore.release()
        semaphore.release()
    
if __name__ == '__main__':
    unittest.main()
