#include <stdio.h>
#include "lexer.h"
#include "parser.h"

void parse_program() {
    token_type current_token = next_token();

    while (current_token != TOKEN_EOF) {
        switch (current_token) {
            case TOKEN_IDENTIFIER:
                printf("Identifier detected.\n");
                break;
            case TOKEN_NUMBER:
                printf("Number detected.\n");
                break;
            case TOKEN_ASSIGNMENT:
                printf("Assignment operator detected.\n");
                break;
            case TOKEN_SEMICOLON:
                printf("Semicolon detected.\n");
                break;
            default:
                printf("Unknown token encountered.\n");
                break;
        }
        current_token = next_token();
    }
}
