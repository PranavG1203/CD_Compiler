#ifndef LEXER_H
#define LEXER_H

#include "tokens.h" // Include tokens.h for Token type

void lexer_init(FILE *source_file);
Token next_token();

// Declare current_token as extern so it can be accessed from parser.c
extern Token current_token;

#endif
