#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "tokens.h"

static char buffer[256];
static int position = 0;

// Define current_token here
Token current_token;

void lexer_init(FILE *source_file) {
    // Initialize lexer state if needed
    fgets(buffer, sizeof(buffer), source_file); // Load first line of the source file
}

Token next_token() {
    while (1) {
        if (position >= strlen(buffer)) {
            return TOKEN_EOF; // End of file
        }

        char c = buffer[position++];
        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            ungetc(c, stdin);
            return TOKEN_NUMBER;
        }

        if (isalpha(c)) {
            ungetc(c, stdin);
            char id[256];
            fscanf(stdin, "%s", id);
            if (strcmp(id, "si") == 0) return TOKEN_SI;
            if (strcmp(id, "sino") == 0) return TOKEN_SINO;
            if (strcmp(id, "imprimir") == 0) return TOKEN_IMPRIMIR;
            if (strcmp(id, "numero") == 0) return TOKEN_NUMERO;
            return TOKEN_IDENTIFIER;
        }

        switch (c) {
            case '=': return TOKEN_ASSIGN;
            case ';': return TOKEN_SEMICOLON;
            case '+': return TOKEN_PLUS;
            case '-': return TOKEN_MINUS;
            case '(': return TOKEN_LPAREN;
            case ')': return TOKEN_RPAREN;
            default:
                printf("Unknown character: %c\n", c);
                return TOKEN_UNKNOWN;
        }
    }
}
