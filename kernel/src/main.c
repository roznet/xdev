//#include "multiboot.h"
#include "monitor.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "paging.h"

//int kernel_main(multiboot_info_t * mboot_ptr)
int kernel_main()
{
    monitor_clear();
    monitor_write( "Hello World!\n" );

    init_gdt();
    init_idt();
    printf("Hello Format HEX: %x  DEC: %i\n", 20, 20 );
    /*
    init_timer(20);
    asm volatile ( "int $0x3" );
    asm volatile ( "int $0x4" );
    // start interrupt...
    asm volatile ( "sti" );
    */

    initialise_paging();
    uint32_t * ptr = (uint32_t*)0xA0000000;
    uint32_t do_page_fault = *ptr;
    monitor_write_hex(do_page_fault);
    return 0xDEADCAFE;
}
