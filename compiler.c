#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <source file>\n", argv[0]);
        return 1;
    }

    // Open the source file
    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL)
    {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    // Initialize the lexer
    lexer_init(source_file);
    next_token();

    // Parse the program and generate C code
    parse_program();

    // Close the source file
    fclose(source_file);

    // Compile the generated C code
    int compile_status = system("gcc generated_code.c -o output_program");
    if (compile_status == 0)
    {
        // Execute the compiled program if compilation was successful
        system("./output_program");
    }
    else
    {
        printf("Compilation failed.\n");
    }

    return 0;
}
