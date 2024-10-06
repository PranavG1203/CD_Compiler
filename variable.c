#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

#define MAX_VARIABLES 100

typedef struct {
    char name[100];
    int value;
} Variable;

Variable variables[MAX_VARIABLES];
int variable_count = 0;

void store_variable(const char *name, int value) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value; // Update existing variable
            return;
        }
    }
    // Add new variable
    strcpy(variables[variable_count].name, name);
    variables[variable_count].value = value;
    variable_count++;
}

int get_variable(const char *name) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value; // Return value of variable
        }
    }
    return 0; // Variable not found, return default
}
