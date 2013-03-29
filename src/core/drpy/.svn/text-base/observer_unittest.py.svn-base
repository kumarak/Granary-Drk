import unittest

from drpy.observer import Subject

class SubjectTestCase(unittest.TestCase):
    def setUp(self):
        self.count1 = 0
        self.count2 = 0
        self.count3 = 0
        self.subject = Subject()

    def event1(self):
        self.count1 += 1

    def event2(self):
        self.count2 += 1

    def remove_during_event(self):
        self.count3 += 1
        self.subject.remove_observer(self.remove_during_event)

    def test_simple(self):
        self.subject.add_observer(self.event1)
        self.subject.notify()
        self.assertEqual(1, self.count1)
        self.subject.remove_observer(self.event1)
        self.subject.notify()
        self.assertEqual(1, self.count1)

        self.subject.add_observer(self.event1)
        self.subject.add_observer(self.event2)
        self.subject.notify()
        self.assertEqual(2, self.count1)
        self.assertEqual(1, self.count2)
    
    def test_multiple(self):
        self.subject.add_observer(self.event1)
        self.subject.add_observer(self.event1)
        self.subject.notify()
        self.assertEqual(2, self.count1)

    def test_remove_during_event(self):
        self.subject.add_observer(self.event1)
        self.subject.add_observer(self.remove_during_event)
        self.subject.add_observer(self.event2)
        self.subject.notify()
        self.assertEqual(1, self.count1)
        self.assertEqual(1, self.count2)
        self.assertEqual(1, self.count3)
        self.subject.notify()
        self.assertEqual(2, self.count1)
        self.assertEqual(2, self.count2)
        self.assertEqual(1, self.count3)
