import string
import subprocess
import optparse
import sys
import shlex

from drpy.observer import Subject

class ShellError(Exception):
    def __init__(self, command_args):
        Exception.__init__(self, command_args)
        self.command_args = command_args

def check_open(args, input_string=None):
    stdin = subprocess.PIPE if input_string else None
    popen = subprocess.Popen(args, stdin=stdin, stdout=subprocess.PIPE)
    result = popen.communicate(input_string)[0]
    if popen.returncode != 0:
        print args, input_string
        raise ShellError(args)
    return result

class Shell(object):
    def __init__(self):
        self.subject = Subject()

    def add_run_observer(self, observer):
        self.subject.add_observer(observer)
    
    def remove_run_observer(self, observer):
        self.subject.remove_observer(self, observer)

    def check_open(self, args, input_string=None):
        self.subject.notify(' '.join(args))
        return check_open(args, input_string)

class SecureShell(Shell):
    def __init__(self, hostname, port, user):
        Shell.__init__(self)
        self.hostname = hostname
        self.port = str(port)
        self.user = user

    def copy_to(self, local_files, remote_dir):
        self.check_open(['scp', '-P', self.port] + local_files +
                        ['%s@%s:%s' % (self.user, self.hostname, remote_dir)])

    def run(self, command):
        return self.check_open(['ssh', '-q', '-t',
                                 '-o', 'NumberOfPasswordPrompts=0',
                                 '-p', self.port,
                                 '%s@%s' % (self.user, self.hostname),
                                 command])

class LocalShell(Shell):
    def run(self, command):
        return self.check_open(['bash', '-c', command])

class RequiredOptionParser(object):
    
    class DefaultSentenil(object):
        def __init__(self, name):
            self.name = name
    
    def __init__(self):
        self.parser = optparse.OptionParser()

    def add_option(self, name, *args, **kwargs):
        if 'default' not in kwargs:
            kwargs['default'] = RequiredOptionParser.DefaultSentenil(name)
        self.parser.add_option(name, *args, **kwargs)

    def parse_args(self):
        (options, args) = self.parser.parse_args()
        missing = None
        for value in options.__dict__.itervalues():
            if isinstance(value, RequiredOptionParser.DefaultSentenil):
                missing = value.name
                print 'Option %s needs to be specified.' % value.name
        if missing:
            raise optparse.OptionError(
                'is required and missing.', missing)
        return (options, args)
