#include <stdio.h>
#include "tokens.h"

extern Token current_token;

// Function to generate code based on a string
void generate_code(const char *code)
{
    printf("Generated code: %s\n", code); // Simulate code generation by printing
}

// Parse a declaration like 'numero a;'
void parse_declaration()
{
    printf("Parsing declaration...\n");
    current_token = next_token(); // Get next token (should be an identifier)
    if (current_token == TOKEN_IDENTIFIER)
    {
        printf("Declaration: variable identifier\n");
        current_token = next_token(); // Get next token (should be ';')
        if (current_token == TOKEN_SEMICOLON)
        {
            printf("Declaration complete.\n");
        }
        else
        {
            printf("Syntax Error: Expected ';' at the end of the declaration.\n");
        }
    }
    else
    {
        printf("Syntax Error: Expected identifier after 'numero'.\n");
    }
}

// Parse an assignment like 'a = 10;'
void parse_assignment()
{
    printf("Parsing assignment...\n");
    current_token = next_token(); // Get next token (should be '=')
    if (current_token == TOKEN_ASSIGN)
    {
        current_token = next_token(); // Get next token (should be a number)
        if (current_token == TOKEN_NUMBER)
        {
            printf("Assignment: assigning value to variable\n");
            current_token = next_token(); // Get next token (should be ';')
            if (current_token == TOKEN_SEMICOLON)
            {
                printf("Assignment complete.\n");
            }
            else
            {
                printf("Syntax Error: Expected ';' at the end of the assignment.\n");
            }
        }
        else
        {
            printf("Syntax Error: Expected a number after '='.\n");
        }
    }
    else
    {
        printf("Syntax Error: Expected '=' after identifier.\n");
    }
}

// Parse a print statement like 'imprimir a;'
void parse_print_statement()
{
    printf("Parsing print statement...\n");
    current_token = next_token(); // Get next token (should be an identifier)
    if (current_token == TOKEN_IDENTIFIER)
    {
        printf("Print: variable identifier\n");
        current_token = next_token(); // Get next token (should be ';')
        if (current_token == TOKEN_SEMICOLON)
        {
            printf("Print statement complete.\n");
        }
        else
        {
            printf("Syntax Error: Expected ';' at the end of the print statement.\n");
        }
    }
    else
    {
        printf("Syntax Error: Expected identifier after 'imprimir'.\n");
    }
}

// Main parsing function to handle different types of statements
void parse_statement()
{
    printf("Parsing statement for token: %d\n", current_token); // Print current token
    switch (current_token)
    {
    case TOKEN_NUMERO:
        parse_declaration();
        break;
    case TOKEN_IDENTIFIER:
        parse_assignment();
        break;
    case TOKEN_IMPRIMIR:
        parse_print_statement();
        break;
    default:
        printf("Syntax Error: Unexpected token '%d'\n", current_token);
        break;
    }
}

// Main function to parse an entire program
void parse_program()
{
    current_token = next_token(); // Get the first token
    while (current_token != TOKEN_EOF)
    {
        parse_statement();
        current_token = next_token(); // Get the next token
    }
}
