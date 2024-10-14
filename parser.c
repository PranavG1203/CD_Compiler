#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "variable.h"

extern int current_token;
extern char current_token_identifier[100];
extern int current_token_value;

void parse_program();
void parse_statement();
void parse_expression();
void parse_if_statement();

void parse_program() {
    while (current_token != TOKEN_EOF) {
        parse_statement();
    }
}

void parse_statement() {
    if (current_token == TOKEN_KEYWORD) {
        if (strcmp(current_token_identifier, "numero") == 0) {
            current_token = next_token();
            if (current_token == TOKEN_IDENTIFIER) {
                char var_name[100];
                strcpy(var_name, current_token_identifier);
                current_token = next_token();
                if (current_token == TOKEN_ASSIGN) {
                    current_token = next_token();
                    if (current_token == TOKEN_NUMBER) {
                        store_variable(var_name, current_token_value);
                        printf("Assigned variable %s = %d\n", var_name, current_token_value);
                        current_token = next_token();
                    }
                }
            }
        } else if (strcmp(current_token_identifier, "imprimir") == 0) {
            current_token = next_token();
            if (current_token == TOKEN_IDENTIFIER) {
                int value = get_variable(current_token_identifier);
                printf("Print variable %s = %d\n", current_token_identifier, value);
                current_token = next_token();
            }
        } else if (strcmp(current_token_identifier, "si") == 0) {
            parse_if_statement();
        }
    } else if (current_token == TOKEN_IDENTIFIER) {
        char var_name[100];
        strcpy(var_name, current_token_identifier);
        current_token = next_token();
        if (current_token == TOKEN_ASSIGN) {
            current_token = next_token();
            if (current_token == TOKEN_NUMBER) {
                store_variable(var_name, current_token_value);
                printf("Updated variable %s = %d\n", var_name, current_token_value);
                current_token = next_token();
            }
        }
    } else {
        current_token = next_token();
    }
}

void parse_if_statement() {
    current_token = next_token();
    if (current_token == TOKEN_LPAREN) {
        current_token = next_token();
        parse_expression();
        if (current_token == TOKEN_RPAREN) {
            current_token = next_token();
            if (current_token == TOKEN_LBRACE) {
                current_token = next_token();
                while (current_token != TOKEN_RBRACE && current_token != TOKEN_EOF) {
                    parse_statement();
                }
                current_token = next_token();
            }
            if (current_token == TOKEN_ELSE) {
                current_token = next_token();
                if (current_token == TOKEN_LBRACE) {
                    current_token = next_token();
                    while (current_token != TOKEN_RBRACE && current_token != TOKEN_EOF) {
                        parse_statement();
                    }
                    current_token = next_token();
                }
            }
        }
    }
}

void parse_expression() {
    if (current_token == TOKEN_IDENTIFIER) {
        current_token = next_token();
        if (current_token == TOKEN_GREATER) {
            current_token = next_token();
            if (current_token == TOKEN_IDENTIFIER || current_token == TOKEN_NUMBER) {
                current_token = next_token();
            }
        }
    }
}
