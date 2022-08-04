#ifndef JLANG_BUILTINS_H
#define JLANG_BUILTINS_H
#include "visitor.h"

AST_J* fptr_print(visitor_J* visitor, AST_J* node, list_J* list);
void builtins_init(list_J* list);
#endif
