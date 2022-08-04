#ifndef JLANG_TOKEN_H
#define JLANG_TOKEN_H
typedef struct TOKEN_STRUCT
{
  char* value;
  enum
  {
    TOKEN_ID,
    TOKEN_EQUALS,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_ARROW_RIGHT,
    TOKEN_INT,
    TOKEN_STRING,
    TOKEN_STATEMENT,
    TOKEN_SEMI,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_DIV,
    TOKEN_MUL,
    TOKEN_EOF,
  } type;
} token_J;

token_J* init_token(char* value, int type);

const char* token_type_to_str(int type);

char* token_to_str(token_J* token);
#endif
