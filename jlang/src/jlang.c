#include "include/jlang.h"
#include "include/lexer.h"
#include "include/io.h"
#include <stdlib.h>

void jlang_compile(char* src)
{
  lexer_J* lexer = init_lexer(src);
  token_J* token = 0;

  while ((token = lexer_next_token(lexer))->type != TOKEN_EOF) {
    printf("%s", token_to_str(token));
  }
}

void jlang_compile_src_file(const char* filename)
{
  char* src = io_jlang_read_file(filename);
  jlang_compile(src);
  free(src);
}
