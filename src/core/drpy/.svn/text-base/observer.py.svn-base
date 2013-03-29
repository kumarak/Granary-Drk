class Subject(object):
    def __init__(self):
        # Use a list instead of a set so an observer can be added multiple times
        # with the expected effect.
        self.observers = []
    
    def add_observer(self, observer):
        self.observers.append(observer)

    def remove_observer(self, observer):
        self.observers.remove(observer)

    def notify(self, *args, **kwargs):
        copy = list(self.observers)
        for observer in copy:
            observer(*args, **kwargs)
