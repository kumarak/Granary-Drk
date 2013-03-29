#!/usr/bin/env python
from drpy.qemu import QEMU

VM_HD_PATH='../debugging/ubuntu-server.qcow2'
VM_USER='peter'

vm = QEMU(cpus=1, mem=1024, hda_path=VM_HD_PATH, user='peter', ssh_port=5555)
try:
    vm.shell.run('sudo halt')
    vm.wait()
finally:
    if vm.running():
        vm.kill()
