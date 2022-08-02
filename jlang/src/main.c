#include <stdio.h>
#include "include/jlang.h"
#include "include/lexer.h"
#include "include/io.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Please specify file.\n\n");
        return 1;
    }

    jlang_compile_src_file(argv[1]);

    return 0;
}
