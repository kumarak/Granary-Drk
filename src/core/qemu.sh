qemu-system-x86_64 -smp 1 -s -m 2048 -hda /home/akshayk/drk.qcow2 -net nic,model=virtio -net "user,hostfwd=tcp::5556-:22" -serial file:/home/akshayk/qemu.log &

