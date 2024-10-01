#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

// Function declarations
void lexer_init(FILE *source_file);          // Initialize lexer with source file
int next_token();                            // Get next token
const char* lexer_get_identifier();          // Get the identifier token value
const char* lexer_get_number();              // Get the number token value

#endif
