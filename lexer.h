#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>  // Include this for FILE

#define TOKEN_KEYWORD 1
#define TOKEN_IDENTIFIER 2
#define TOKEN_NUMBER 3
#define TOKEN_ASSIGN 4
#define TOKEN_SEMICOLON 5
#define TOKEN_LBRACE 6
#define TOKEN_RBRACE 7
#define TOKEN_OPERATOR 8
#define TOKEN_EOF 9
#define TOKEN_IF 100
#define TOKEN_ELSE 101
#define TOKEN_GREATER 102 // For the '>' operator
#define TOKEN_LPAREN 103 // For '('
#define TOKEN_RPAREN 104 // For ')'



extern int current_token; 
extern char current_token_identifier[100]; 
extern int current_token_value; 
extern FILE *input_file; // This remains as extern

void init_lexer(const char *filename);
int next_token();

#endif
