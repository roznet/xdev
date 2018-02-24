#include "monitor.h"
#include "panic.h"

void panic(char * msg )
{
    printf( "*** System Panic: %s\n", msg );
    while(1);
}
