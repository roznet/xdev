# James Molloy Toy Kernel tutorial

## resources used

Trying to go through the james molloy tutorial using latest grub/multiboot2 and qemu.

- kernel tutorial [http://www.jamesmolloy.co.uk/tutorial_html](http://www.jamesmolloy.co.uk/tutorial_html)
- kernel tutorial example implementation [https://github.com/berkus/jamesm-tutorials.git](https://github.com/berkus/jamesm-tutorials.git)
- Kernel multiboot2/grub example [https://github.com/davidcallanan/os-series](https://github.com/berkus/jamesm-tutorials.git)

## Building on macos

Use docker to get linux build environment and run make

```sh
docker build buildenv -t kernel-buildenv
docker run --rm -it -v "${PWD}:/usr/bld" kernel-buildenv
```

To cleanup:

```sh
docker rmi kernel-buildenv -f
```

## building on linux/ubuntu

run the `apt install` from the Dockerfile and just use `make`

## Running emulator

once `os.iso` is built

```sh
qemu-system-i386 -cdrom os.iso
```

To debug

```
# -s is shortcut for -gdb tcp:1234
# -S to stop before starting to attach debugger
qemu-system-i386 -s -S -cdrom os.iso
```

Start `gdb` in parallel and do

```
(gdb) attach remote localhost:1234
(gdb) add-symbol-file iso/boot/kernel.elf
(gdb) break kernel_main
(gdb) continue
```

