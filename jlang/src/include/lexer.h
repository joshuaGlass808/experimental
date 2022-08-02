#ifndef JLANG_LEXER_H
#define JLANG_LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT
{
    char* src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_J;

lexer_J* init_lexer(char* src);

void lexer_advance(lexer_J* lexer);

char lexer_peek(lexer_J* lexer, int offset);

token_J* lexer_advance_with(lexer_J* lexer, token_J* token);

token_J* lexer_advance_current(lexer_J* lexer, int type);

void lexer_skip_whitespace(lexer_J* lexer);

token_J* lexer_parse_id(lexer_J* lexer);

token_J* lexer_parse_number(lexer_J* lexer);

token_J* lexer_next_token(lexer_J* lexer);
#endif
