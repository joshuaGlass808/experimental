/**
 * Not in use at the moment
 *
#include "include/builtins.h"
#include "include/utils.h"
#include "include/as_frontend.h"
#include <string.h>
#include <stdio.h>

void builtins_register_fptr(list_J* list, const char* name, AST_J* (*fptr)(visitor_J* visitor, AST_J* node, list_J* list))
{
  AST_J* fptr_print_var = init_ast(AST_VARIABLE);
  fptr_print_var->name = mkstr(name);
  fptr_print_var->fptr = fptr;

  list_push(list, fptr_print_var);
}

void builtins_init(list_J* list)
{
}*/
