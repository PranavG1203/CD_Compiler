#include <stdio.h>
#include <ctype.h>
#include "lexer.h"

char current_char;
FILE *source;

void init_lexer(FILE *input_file) {
    source = input_file;
    current_char = getc(source);
}

void advance() {
    current_char = getc(source);
}

// Helper function to check if the current character is part of an identifier
int is_identifier_char(char c) {
    return isalpha(c) || c == '_';
}

token_type next_token() {
    // Skip whitespace
    while (isspace(current_char)) {
        advance();
    }

    // Handle EOF
    if (current_char == EOF) {
        return TOKEN_EOF;
    }

    // Handle identifiers (e.g., 'imprimir', 'si', etc.)
    if (is_identifier_char(current_char)) {
        // Read the entire identifier
        char identifier[100];  // Buffer for the identifier (size can be adjusted)
        int i = 0;

        while (is_identifier_char(current_char)) {
            identifier[i++] = current_char;
            advance();
        }
        identifier[i] = '\0';  // Null-terminate the string

        // Print out the identifier for debugging
        printf("Identifier found: %s\n", identifier);

        return TOKEN_IDENTIFIER;
    }

    // Handle numbers
    if (isdigit(current_char)) {
        // Read the entire number
        char number[100];
        int i = 0;

        while (isdigit(current_char)) {
            number[i++] = current_char;
            advance();
        }
        number[i] = '\0';  // Null-terminate the number string

        printf("Number found: %s\n", number);

        return TOKEN_NUMBER;
    }

    // Handle assignment '='
    if (current_char == '=') {
        advance();
        return TOKEN_ASSIGNMENT;
    }

    // Handle semicolon ';'
    if (current_char == ';') {
        advance();
        return TOKEN_SEMICOLON;
    }

    // Unknown token (advance and return unknown)
    advance();
    return TOKEN_UNKNOWN;
}
