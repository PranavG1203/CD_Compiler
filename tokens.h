#ifndef TOKENS_H
#define TOKENS_H

// Token type
typedef enum {
    TOKEN_NUMERO,    // For 'numero'
    TOKEN_SI,        // For 'si'
    TOKEN_SINO,      // For 'sino'
    TOKEN_IMPRIMIR,  // For 'imprimir'
    TOKEN_IDENTIFIER, // For variable names
    TOKEN_NUMBER,     // For numeric literals
    TOKEN_ASSIGN,     // For '='
    TOKEN_PLUS,       // For '+'
    TOKEN_MINUS,      // For '-'
    TOKEN_SEMICOLON,  // For ';'
    TOKEN_LPAREN,    // For '('
    TOKEN_RPAREN,    // For ')'
    TOKEN_EOF,       // End of file
    TOKEN_UNKNOWN     // Unknown token
} Token;

#endif
