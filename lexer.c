#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tokens.h"
#include <stdlib.h>

extern FILE *source_file; // Assuming source_file is declared somewhere

char buffer[256];  // Buffer to hold current lexeme
int number_buffer; // Buffer to hold numeric literals

// Function to retrieve the next token from the input source
Token next_token()
{
    if (fscanf(source_file, "%s", buffer) == EOF)
    {
        printf("Token identified: %d (EOF)\n", TOKEN_EOF);
        return TOKEN_EOF;
    }

    // Check for 'numero' keyword
    if (strcmp(buffer, "numero") == 0)
    {
        printf("Token identified: %d (numero)\n", TOKEN_NUMERO);
        return TOKEN_NUMERO;
    }

    // Check for 'si' keyword
    if (strcmp(buffer, "si") == 0)
    {
        printf("Token identified: %d (si)\n", TOKEN_SI);
        return TOKEN_SI;
    }

    // Check for 'sino' keyword
    if (strcmp(buffer, "sino") == 0)
    {
        printf("Token identified: %d (sino)\n", TOKEN_SINO);
        return TOKEN_SINO;
    }

    // Check for 'para' keyword
    if (strcmp(buffer, "para") == 0)
    {
        printf("Token identified: %d (para)\n", TOKEN_PARA);
        return TOKEN_PARA;
    }

    // Check for 'mientras' keyword
    if (strcmp(buffer, "mientras") == 0)
    {
        printf("Token identified: %d (mientras)\n", TOKEN_MIENTRAS);
        return TOKEN_MIENTRAS;
    }

    // Check for 'imprimir' keyword
    if (strcmp(buffer, "imprimir") == 0)
    {
        printf("Token identified: %d (imprimir)\n", TOKEN_IMPRIMIR);
        return TOKEN_IMPRIMIR;
    }

    // Check for identifiers (starting with a letter)
    if (isalpha(buffer[0]))
    {
        printf("Token identified: %d (identifier)\n", TOKEN_IDENTIFIER);
        return TOKEN_IDENTIFIER;
    }

    // Check for numeric literals (starting with a digit)
    if (isdigit(buffer[0]))
    {
        number_buffer = atoi(buffer); // Convert string to int
        printf("Token identified: %d (number)\n", TOKEN_NUMBER);
        return TOKEN_NUMBER;
    }

    // Check for operators and delimiters
    if (buffer[0] == '=')
    {
        printf("Token identified: %d (assignment)\n", TOKEN_ASSIGN);
        return TOKEN_ASSIGN;
    }
    if (buffer[0] == '+')
    {
        printf("Token identified: %d (plus)\n", TOKEN_PLUS);
        return TOKEN_PLUS;
    }
    if (buffer[0] == '-')
    {
        printf("Token identified: %d (minus)\n", TOKEN_MINUS);
        return TOKEN_MINUS;
    }
    if (buffer[0] == ';')
    {
        printf("Token identified: %d (semicolon)\n", TOKEN_SEMICOLON);
        return TOKEN_SEMICOLON;
    }

    // If no valid token is identified
    printf("Unknown token: %s\n", buffer);
    return -1; // Return an error token
}
