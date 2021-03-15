#ifndef PAGING_H
#define PAGING_H

#include "common.h"

typedef struct {
    uint32_t present : 1;
    uint32_t rw : 1;
    uint32_t user : 1;
    uint32_t accessed : 1;
    uint32_t dirty : 1;
    uint32_t unused : 7;
    uint32_t frame : 20;
} page_t;

typedef struct {
    page_t pages[1024];
} page_table_t;

typedef struct {
    page_t * tables[1024];
    uint32_t tablesPhysical[1024];
    uint32_t physicalAddr;
} page_directory_t;

void initialiase_paging();

#endif
