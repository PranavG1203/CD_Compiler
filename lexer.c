#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
        int i = 0;
        while (isalnum(current_char)) {
            current_token_identifier[i++] = current_char;
            current_char = fgetc(input_file);
        }
        current_token_identifier[i] = '\0';

        if (strcmp(current_token_identifier, "numero") == 0) {
            current_token = TOKEN_KEYWORD;
        } else if (strcmp(current_token_identifier, "si") == 0) {
            current_token = TOKEN_IF;
        } else if (strcmp(current_token_identifier, "sino") == 0) {
            current_token = TOKEN_ELSE;
        } else if (strcmp(current_token_identifier, "imprimir") == 0) {
            current_token = TOKEN_KEYWORD;
        } else {
            current_token = TOKEN_IDENTIFIER;
        }

        printf("Token: %d, Identifier: %s\n", current_token, current_token_identifier);
        return current_token;
    }

    if (isdigit(current_char)) {
        current_token_value = 0;
        while (isdigit(current_char)) {
            current_token_value = current_token_value * 10 + (current_char - '0');
            current_char = fgetc(input_file);
        }
        current_token = TOKEN_NUMBER;
        printf("Token: %d, Value: %d\n", current_token, current_token_value);
        return current_token;
    }

    switch (current_char) {
        case '=': current_token = TOKEN_ASSIGN; break;
        case ';': current_token = TOKEN_SEMICOLON; break;
        case '{': current_token = TOKEN_LBRACE; break;
        case '}': current_token = TOKEN_RBRACE; break;
        case '(': current_token = TOKEN_LPAREN; break;
        case ')': current_token = TOKEN_RPAREN; break;
        case '>': current_token = TOKEN_GREATER; break;
        case EOF: current_token = TOKEN_EOF; break;
        default:
            printf("Error: Unknown character: %c\n", current_char);
            exit(EXIT_FAILURE);
    }

    printf("Token: %d, Char: %c\n", current_token, current_char);
    current_char = fgetc(input_file); // Advance to next character
    return current_token;
}
