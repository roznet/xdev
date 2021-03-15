#include "common.h"
extern uint32_t end;
uint32_t placement_address = NULL;

uint32_t kmalloc_ap( uint32_t sz, int align, uint32_t * phys)
{
    if( placement_address == NULL)
    {
        placement_address = end;
    }
    if( align == 1 && (placement_address & 0xFFFFF000) )
    {
        placement_address &= 0xFFFFF000;
        placement_address += 0x1000;
    }
    if( phys )
    {
        *phys = placement_address;
    }
    uint32_t tmp = placement_address;
    placement_address += sz;
    return tmp;
}

uint32_t kmalloc_a( uint32_t sz )
{
    return kmalloc_ap( sz, 1, NULL);
}

uint32_t kmalloc( uint32_t sz )
{
    return kmalloc_ap( sz, 0, NULL );
}
