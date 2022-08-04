#include "include/jlang.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/io.h"
#include "include/visitor.h"
#include "include/as_frontend.h"


void jlang_compile(char* src)
{
  lexer_J* lexer = init_lexer(src);
  parser_J* parser = init_parser(lexer);
  AST_J* root = parser_parse(parser);

  visitor_J* visitor = init_visitor();
  AST_J* optimized_root = visitor_visit(visitor, root, init_list(sizeof(struct AST_STRUCT*)), init_stack_frame());
  
  char* s = as_f_root(optimized_root, init_list(sizeof(struct AST_STRUCT*)));

  jlang_write_file("a.s", s);
  jlang_write_file("a.s.txt", s);
  sh("as --32 a.s -o asm.o");
  sh("ld asm.o -o asm.out -m elf_i386");
  printf("%s", sh("./asm.out"));
  sh("rm asm.out asm.o");
}

void jlang_compile_file(const char* filename)
{
  char* src =jlang_read_file(filename);
  jlang_compile(src);
  free(src);
}
