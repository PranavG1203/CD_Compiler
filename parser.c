#include <stdio.h>
#include "parser.h"
#include "lexer.h"

void parse_program() {
    lexer_init(stdin); // Initialize lexer with input from stdin
    current_token = next_token(); // Get the first token

    while (current_token != TOKEN_EOF) {
        parse_statement(); // Parse statements
        current_token = next_token(); // Get the next token
    }
}

void parse_statement() {
    switch (current_token) {
        case TOKEN_SI:
            // Handle 'si' (if statement)
            break;
        case TOKEN_IMPRIMIR:
            // Handle 'imprimir' (print statement)
            break;
        // Add more cases as needed
        default:
            printf("Unexpected token: %d\n", current_token);
            break;
    }
}
