target remote localhost:1234
add-symbol-file iso/boot/kernel.elf
break kernel_main
# usage: xxd pointer size
#        xxd &ptr 10
define xxd
dump binary memory .gdb.bin $arg0 $arg0+$arg1
shell xxd .gdb.bin
end
continue
