#ifndef COMPILER_ERRORS_H
#define COMPILER_ERRORS_H
#include "AST.h"
void assert_call_matches_signature(AST_J* call_node, AST_J* func_node);
#endif
