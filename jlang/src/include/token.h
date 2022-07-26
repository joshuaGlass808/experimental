#ifndef JLANG_TOKEN_H
#define JLANG_TOKEN_H
typedef struct TOKEN_STRUCT
{
    char* value;
    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_TYPE_DECLARATION_ASSIGNMENT,
        TOKEN_COMMA,
        TOKEN_LT,
        TOKEN_GT,
        TOKEN_RIGHT_ARROW,
        TOKEN_INT,
        TOKEN_SEMI,
        TOKEN_EOF,
    } type;
} token_J;

token_J* init_token(char* value, int type);
#endif