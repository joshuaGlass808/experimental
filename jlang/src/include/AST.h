#ifndef JLANG_AST_H
#define JLANG_AST_H
#include "list.h"
#include "stack_frame.h"
#include "types.h"

struct VISITOR_STRUCT;

typedef struct AST_STRUCT
{
  enum
  {
    AST_COMPOUND,
    AST_FUNCTION,
    AST_CALL,
    AST_ASSIGNMENT = 99,
    AST_DEFINITION_TYPE,
    AST_VARIABLE,
    AST_STATEMENT_RETURN,
    AST_ACCESS,
    AST_INT,
    AST_STRING,
    AST_BINOP,
    AST_NOOP,
  } type;

  data_type dtype;
  
  list_J* children;
  char* name;
  char* string_value;
  struct AST_STRUCT* value;
  struct AST_STRUCT* left;
  struct AST_STRUCT* right;
  int op;
  int int_value;
  int id;
  int stack_index;
  int multiplier;
  struct AST_STRUCT* (*fptr)(struct VISITOR_STRUCT* visitor, struct AST_STRUCT* node, list_J* list);
  stack_frame_J* stack_frame;
} AST_J;

AST_J* init_ast(int type);
#endif
