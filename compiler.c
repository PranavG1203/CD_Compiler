#include <stdio.h>
#include <stdlib.h> // Add this line for EXIT_FAILURE and EXIT_SUCCESS
#include "lexer.h"
#include "parser.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    init_lexer(argv[1]);
    next_token(); // Initialize the first token
    parse_program(); // Start parsing

    fclose(input_file); // Close the file
    return EXIT_SUCCESS;
}
