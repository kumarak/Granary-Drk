import unittest
import getpass

from drpy.shutil import check_open, LocalShell, SecureShell, ShellError

class CheckOpenTestCase(unittest.TestCase):
    def test_check_open(self):
        self.assertEqual('hi', check_open(['echo', '-n', 'hi']))
        self.assertRaises(ShellError, check_open, ['false'])
        self.assertEqual('hi', check_open(['cat'], input_string='hi'))

class ShellTest(object):
    def test_simple_run(self):
        self.assertEqual('hi', self.shell.run('echo -n hi'))
        self.assertRaises(ShellError, self.shell.run , 'false')

    def test_bash_syntax(self):
        self.assertEqual('b', self.shell.run('(false && echo a) || echo -n b'))
        self.assertEqual('12',
                         self.shell.run('for x in 1 2; do echo -n $x; done'))
        self.assertEqual('hi', self.shell.run('echo -n $(echo hi)'))

    def test_run_observer(self):
        commands = []
        self.shell.add_run_observer(commands.append)
        self.shell.run('true || false')
        self.assertEqual(1, len(commands))
        self.assertNotEqual(-1, commands[0].find('true || false'))

class LocalShellTest(ShellTest, unittest.TestCase):
    def setUp(self):
        self.shell = LocalShell()

class SecureShellTest(ShellTest, unittest.TestCase):
    def setUp(self):
        # TODO(peter): Make this configurable? Right now, it assumes that
        # passwordless SSH is setup.
        self.shell = SecureShell('localhost', 22, getpass.getuser())
    
if __name__ == '__main__':
    unittest.main()
