#ifndef JLANG_LIST_H
#define JLANG_LIST_H
#include <stdlib.h>

typedef struct LIST_STRUCT
{
  void** items;
  size_t size;
  size_t item_size;
} list_J;

list_J* init_list(size_t item_size);

void list_push(list_J* list, void* item);

int list_indexof_str(list_J* list, char* item);
#endif
