#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_BUFSIZE 8

tokenized_line arg_parser(char* line){
    int bufsize = INITIAL_BUFSIZE;
    tokenized_line tok_line;
    tok_line.args = malloc(bufsize * sizeof(char));

    // applicare strtok a line

    return tok_line;
}