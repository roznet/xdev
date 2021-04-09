#include "multiboot2.h"
#include "monitor.h"

uint32_t align_ptr(uint32_t ptr, uint8_t alignment ){
  return ((ptr / alignment) * alignment) + alignment;
}

void describe_multiboot2_tag(multiboot2_info_tag_t *tag) {
  switch (tag->type) {
  case 0: {
    printf("tag %i end\n", tag->type);
    return;
  }
  case 1: {
    multiboot2_info_command_line_t *command_line =
        (multiboot2_info_command_line_t *)tag;
    printf("tag %i boot command line %s\n", tag->type, command_line->command_line);
    break;
  }
  case 2: {
    multiboot2_info_bootloader_name_t *loader_name =
        (multiboot2_info_bootloader_name_t *)tag;
    printf("tag %i bootloader name: %s\n", tag->type, loader_name->bootloader_name);
    break;
  }
  case 3: {
    multiboot2_info_module_t *module = (multiboot2_info_module_t *)tag;
    printf("tag %i module [%x %x]: %s\n", tag->type, module->mod_start, module->mod_end,
           module->module_name);
    break;
  }
  default:
    printf("tag %i\n", tag->type);
    break;
  }
}

void parse_multiboot2(multiboot2_info_t *info) {
  uint32_t info_start_p = (uint32_t)info;
  uint32_t info_end_p = info_start_p + info->total_size;
  info_start_p += 8;
  while (info_start_p < info_end_p) {
    multiboot2_info_tag_t *tag = (multiboot2_info_tag_t *)(info_start_p);

    describe_multiboot2_tag(tag);

    if( tag->type == 0){
      return;
    }
    info_start_p += tag->size;
    info_start_p = align_ptr(info_start_p, 8); 
  }
}
