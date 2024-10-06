#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include for strcmp and strcpy
#include "lexer.h"

FILE *input_file; 
char current_char;

int current_token; 
char current_token_identifier[100]; 
int current_token_value; 

void init_lexer(const char *filename) {
    input_file = fopen(filename, "r");
    if (!input_file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    current_char = fgetc(input_file);
}

int next_token() {
    while (isspace(current_char)) {
        current_char = fgetc(input_file);
    }

    if (isalpha(current_char)) {
        // Handle identifiers or keywords
        int i = 0;
        while (isalnum(current_char)) {
            current_token_identifier[i++] = current_char;
            current_char = fgetc(input_file);
        }
        current_token_identifier[i] = '\0'; // Null-terminate the string
        
        // Handle keywords like 'numero', 'si', and 'sino'
        if (strcmp(current_token_identifier, "numero") == 0) {
            return TOKEN_KEYWORD; // Example for 'numero'
        } else if (strcmp(current_token_identifier, "si") == 0) {
            return TOKEN_IF; // If token
        } else if (strcmp(current_token_identifier, "sino") == 0) {
            return TOKEN_ELSE; // Else token
        } else {
            return TOKEN_IDENTIFIER; // Regular identifier
        }
    }

    if (isdigit(current_char)) {
        // Handle numbers
        current_token_value = 0; // Reset value
        while (isdigit(current_char)) {
            current_token_value = current_token_value * 10 + (current_char - '0'); // Build the integer value
            current_char = fgetc(input_file);
        }
        return TOKEN_NUMBER;
    }

    // Handle other tokens (assignment, semicolon, etc.)
    switch (current_char) {
        case '=':
            current_char = fgetc(input_file);
            return TOKEN_ASSIGN;
        case ';':
            current_char = fgetc(input_file);
            return TOKEN_SEMICOLON;
        case '{':
            current_char = fgetc(input_file);
            return TOKEN_LBRACE;
        case '}':
            current_char = fgetc(input_file);
            return TOKEN_RBRACE;
        case '(':
            current_char = fgetc(input_file);
            return TOKEN_LPAREN;
        case ')':
            current_char = fgetc(input_file);
            return TOKEN_RPAREN;
        case '>':
            current_char = fgetc(input_file);
            return TOKEN_GREATER; // Add this token for '>'
        case EOF:
            return TOKEN_EOF;
        default:
            printf("Error: Unknown character: %c\n", current_char);
            exit(EXIT_FAILURE);
    }
}
