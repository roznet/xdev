# build:

docker build buildenv -t kernel-buildenv

docker run --rm -it -v "${PWD}:/usr/bld" kernel-buildenv

cleanup
docker rmi kernel-buildenv -f


# run emulator

qemu-system-i386 -cdrom os.iso
