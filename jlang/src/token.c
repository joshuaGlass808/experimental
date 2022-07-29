#include "include/token.h"
#include <stdlib.h>

token_J* init_token(char* value, int type)
{
    token_J* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}
