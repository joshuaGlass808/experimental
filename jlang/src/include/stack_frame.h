#ifndef JLANG_STACK_FRAME_H
#define JLANG_STACK_FRAME_H
#include "list.h"
typedef struct STACK_FRAME_STRUCT
{
  list_J* stack;
} stack_frame_J;

stack_frame_J* init_stack_frame();
#endif
