#ifndef JLANG_PARSER_H
#define JLANG_PARSER_H
#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT
{
  lexer_J* lexer;
  token_J* token;
} parser_J;

parser_J* init_parser(lexer_J* lexer);

token_J* parser_eat(parser_J* parser, int type);

AST_J* parser_parse(parser_J* parser);

AST_J* parser_parse_factor(parser_J* parser);

AST_J* parser_parse_term(parser_J* parser);

AST_J* parser_parse_expr(parser_J* parser);

AST_J* parser_parse_statement(parser_J* parser);

AST_J* parser_parse_list(parser_J* parser);

AST_J* parser_parse_string(parser_J* parser);

AST_J* parser_parse_compound(parser_J* parser);
#endif
