import sys
import logging
# Hack to add local path so we can import our drpy packages. I don't know why
# GDB's embedded python doesn't have . on the path by default.
sys.path.append('.')
import drpy.gdbcon
from drpy.debugger import GDBDebugger, DebuggerExitMonitor, DebuggerExitException
from drpy.future import Future, FutureRunner, TimeoutException, TimeoutMonitor
from drpy.loader import DynamoRIOOptions, LoaderOptions, RemoteLoader
from drpy.shutil import SecureShell
from drpy.machine import QEMU

def main(gdb_stub):
    debugger = GDBDebugger(gdb_stub)
    machine = QEMU.create_from_running_vm('peter', 5555)
    shell = machine.get_shell()
    loader = RemoteLoader(shell, debugger,
                          LoaderOptions(),
                          DynamoRIOOptions.create_from_file('dr_options'))
    debugger.set_main_symbol_file('../debugging/linux-2.6.32/vmlinux')
    loader.load()
    machine.attach_debugger(debugger)
    for bp in ['external_error', 'os_terminate', 'panic', 'oops_begin']:
        debugger.add_breakpoint(bp)
    debugger.resume()
    loader.init()

logging.basicConfig(level=logging.DEBUG)
drpy.gdbcon.start_server(main)
