#include <stdio.h>
#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <source file>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (!source_file) {
        printf("Error: Could not open source file %s\n", argv[1]);
        return 1;
    }

    // Initialize lexer and parser
    init_lexer(source_file);
    parse_program();

    fclose(source_file);
    return 0;
}
