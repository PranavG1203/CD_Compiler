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
            // Variable declaration
            current_token = next_token(); // Move to next token
            if (current_token == TOKEN_IDENTIFIER) {
                printf("Parsed variable declaration: %s\n", current_token_identifier);
                store_variable(current_token_identifier, 0); // Store variable with initial value 0
                current_token = next_token(); // Move to next token
                if (current_token == TOKEN_ASSIGN) {
                    current_token = next_token(); // Move to next token
                    if (current_token == TOKEN_NUMBER) {
                        printf("Assigned value to variable: %s = %d\n", current_token_identifier, current_token_value);
                        store_variable(current_token_identifier, current_token_value);
                        current_token = next_token(); // Move to next token
                    }
                }
            }
        } else if (strcmp(current_token_identifier, "imprimir") == 0) {
            // Print statement
            current_token = next_token(); // Move to next token
            if (current_token == TOKEN_IDENTIFIER) {
                printf("Print variable: %s\n", current_token_identifier);
                current_token = next_token(); // Move to next token
            }
        } else if (strcmp(current_token_identifier, "si") == 0) {
            // If statement
            parse_if_statement();
        }
    } else if (current_token == TOKEN_IDENTIFIER) {
        // Assignment statement
        char var_name[100];
        strcpy(var_name, current_token_identifier);
        current_token = next_token(); // Move to next token
        if (current_token == TOKEN_ASSIGN) {
            current_token = next_token(); // Move to next token
            if (current_token == TOKEN_NUMBER) {
                printf("%d\n", current_token_value);
                store_variable(var_name, current_token_value);
                current_token = next_token(); // Move to next token
            }
        }
    } else {
        // If current token does not match any expected, consume and report error
        current_token = next_token();
    }
}

void parse_if_statement() {
    current_token = next_token(); // Move to next token
    if (current_token == TOKEN_LPAREN) {
        current_token = next_token(); // Move to next token
        parse_expression(); // Parse the expression for the condition
        if (current_token == TOKEN_RPAREN) {
            current_token = next_token(); // Move to next token
            if (current_token == TOKEN_LBRACE) {
                // Execute the statements within the braces
                current_token = next_token(); // Move to next token
                while (current_token != TOKEN_RBRACE && current_token != TOKEN_EOF) {
                    parse_statement(); // Parse statements inside the if block
                }
                current_token = next_token(); // Move past the closing brace
            }
        }
    }
}

void parse_expression() {
    // Simple expression parser (for now just checks for variable and comparisons)
    if (current_token == TOKEN_IDENTIFIER) {
        // Here, you could add more logic for checking the comparison
        current_token = next_token();
        if (current_token == TOKEN_GREATER) {
            current_token = next_token(); // Move to next token
            if (current_token == TOKEN_IDENTIFIER || current_token == TOKEN_NUMBER) {
                // Check the second identifier or number
                current_token = next_token();
            }
        }
    }
}
