#include "../../src/include/jlang.h"
#include "../../src/include/io.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_compiler_does_not_segfault()
{
 jlang_compile_file("src/input_files/hello_world.j");
  assert(1);
  printf("[Success]: test_compiler_does_not_segfault\n");
}

void test_output_hello_world()
{
 jlang_compile_file("src/input_files/hello_world.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/hello_world.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[Success]: test_output_hello_world\n");
}

void test_output_variables()
{
 jlang_compile_file("src/input_files/variables.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/variables.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[Success]: test_output_variables\n");
}

void test_output_arith_add()
{
 jlang_compile_file("src/input_files/arith_add.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/arith_add.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[success]: test_output_arith_add\n");
}

void test_output_arith_div()
{
 jlang_compile_file("src/input_files/arith_div.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/arith_div.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[Success]: test_output_arith_div\n");
}

void test_output_arith_mul()
{
 jlang_compile_file("src/input_files/arith_mul.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/arith_mul.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[Success]: test_output_arith_mul\n");
}

void test_output_arith_sub()
{
 jlang_compile_file("src/input_files/arith_sub.j");
  char* output = sh("./a.out");
  char* expected_output =jlang_read_file("src/output_files/arith_sub.j");
  assert(strcmp(output, expected_output) == 0);
  printf("[Success]: test_output_arith_sub\n");
}

int main(int argc, char* argv[])
{
  test_compiler_does_not_segfault();
  test_output_hello_world();
  test_output_variables();
  test_output_arith_add();
  test_output_arith_div();
  test_output_arith_mul();


  printf("[Success]: All tests completed successfully!\n");
  return 0;
}
