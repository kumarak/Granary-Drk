import shlex
import os
import time
from subprocess import Popen
from drpy.shutil import SecureShell

class QEMU(object):
    DEFAULT_GDB_PORT=1234

    def __init__(self, user, ssh_port, create, cpus, mem, hda_path, gdb_port):
        if create:
            self.startup_command = shlex.split('''
                /usr/bin/qemu-system-x86_64
                -smp %d -gdb tcp::%d -m %d -hda %s -net nic,model=virtio -net
                "user,hostfwd=tcp::%d-:22" -nographic
                ''' % (cpus, gdb_port, mem, hda_path, ssh_port))
        else:
            self.startup_command = None
        self.gdb_port = gdb_port
        self.shell = SecureShell('localhost', ssh_port, user)
        self.process = None

    @staticmethod
    def create_from_file(user, ssh_port, cpus, mem, hda_path, gdb_port):
        return QEMU(user, ssh_port, True, cpus, mem, hda_path, gdb_port)

    @staticmethod
    def create_from_running_vm(user, ssh_port, gdb_port=DEFAULT_GDB_PORT):
        return QEMU(user, ssh_port, False, None, None, None, gdb_port)

    def attach_debugger(self, debugger):
        debugger.attach_tcp('localhost', self.gdb_port)

    def get_shell(self):
        return self.shell

    def kill(self):
        assert self.startup_command != None
        self.process.kill()

    def running(self):
        assert self.startup_command != None
        if self.process == None:
            return False
        return self.process.poll()

    def run(self):
        assert self.startup_command != None
        assert not self.running()
        self.process = Popen(self.args)
        if self.process.poll() and self.process.returncode != 0:
            raise Exception('Could not start vm.')
        try:
            time.sleep(1)
            self.shell.run('true')
        except Exception:
            self.process.kill()
            raise
        assert self.running()

    def wait(self):
        assert self.startup_command != None
        return self.process.wait()
