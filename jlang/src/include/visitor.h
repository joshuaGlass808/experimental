#ifndef JLANG_VISITOR_H
#define JLANG_VISITOR_H
#include "AST.h"
#include "list.h"
#include "stack_frame.h"

typedef struct VISITOR_STRUCT
{
  AST_J* object;
} visitor_J;

visitor_J* init_visitor();

AST_J* visitor_visit(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);

AST_J* visitor_visit_compound(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_assignment(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_variable(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_function(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_call(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_int(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_string(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_binop(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_statement_return(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
AST_J* visitor_visit_access(visitor_J* visitor, AST_J* node, list_J* list, stack_frame_J* stack_frame);
#endif
