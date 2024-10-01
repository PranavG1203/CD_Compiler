#ifndef TOKENS_H
#define TOKENS_H

// Token definitions for Spanish keywords
#define TOKEN_NUMERO    1  // For 'numero' (int, float, double)
#define TOKEN_SI        2  // For 'si' (if)
#define TOKEN_SINO      3  // For 'sino' (else)
#define TOKEN_PARA      4  // For 'para' (for)
#define TOKEN_MIENTRAS  5  // For 'mientras' (while)
#define TOKEN_DEVOLVER  6  // For 'devolver' (return)
#define TOKEN_IMPRIMIR  7  // For 'imprimir' (printf)
#define TOKEN_LEER      8  // For 'leer' (scanf)
#define TOKEN_VACIO     9  // For 'vacio' (void)
#define TOKEN_CARACTER  10 // For 'caracter' (char)

// General tokens
#define TOKEN_IDENTIFIER 11 // For variable names
#define TOKEN_NUMBER     12 // For numeric literals
#define TOKEN_ASSIGN     13 // For '='
#define TOKEN_PLUS       14 // For '+'
#define TOKEN_MINUS      15 // For '-'
#define TOKEN_SEMICOLON  16 // For ';'
#define TOKEN_LPAREN     17 // For '('
#define TOKEN_RPAREN     18 // For ')'
#define TOKEN_EOF        19 // End of file

#endif
