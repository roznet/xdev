//

#include "common.h"

typedef struct  {
  uint32_t total_size;
  uint32_t reserved;
} __attribute__((packed)) multiboot2_info_t;

typedef struct  {
  uint32_t type;
  uint32_t size;
} __attribute__((packed)) multiboot2_info_tag_t;

typedef struct {
  uint32_t type;
  uint32_t size;
  char command_line[];
} __attribute__((packed)) multiboot2_info_command_line_t;

typedef struct {
  uint32_t type;
  uint32_t size;

  char bootloader_name[];
} __attribute__((packed)) multiboot2_info_bootloader_name_t;

typedef struct {
  uint32_t type;
  uint32_t size;
  uint32_t mod_start;
  uint32_t mod_end;
  char module_name[];
} __attribute__((packed)) multiboot2_info_module_t;



void parse_multiboot2(multiboot2_info_t * info );
