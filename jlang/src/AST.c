#include "include/AST.h"
#include <stdlib.h>


AST_J* init_ast(int type)
{
  AST_J* ast = calloc(1, sizeof(struct AST_STRUCT));
  ast->type = type;

  if (type == AST_COMPOUND)
    ast->children = init_list(sizeof(struct AST_STRUCT*));

  ast->stack_frame = (void*)0;
  ast->multiplier = 1;
  ast->dtype = DATA_TYPE_UNKNOWN;

  return ast;
}
