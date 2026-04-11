#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_BUFSIZE 8

char** arg_parser(char* line){
    int bufsize = INITIAL_BUFSIZE;
    char** tokenized_args = malloc(bufsize * sizeof(char));

    // applicare strtok a line

    return tokenized_args;
}