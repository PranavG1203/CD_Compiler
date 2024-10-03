#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <source file>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (!source_file) {
        perror("Failed to open source file");
        return 1;
    }

    lexer_init(source_file);
    parse_program();

    fclose(source_file);
    return 0;
}
