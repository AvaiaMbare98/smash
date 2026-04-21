#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_BUFSIZE 8
#define TOK_DELIMETER " \n\t\a\r"

tokenized_line arg_parser(char* line){
    if(line == NULL){
        tokenized_line tok_line;
        tok_line.memory = INITIAL_BUFSIZE;
        tok_line.args = malloc(tok_line.memory * sizeof(char*));
        tok_line.args[0] = NULL;
        tok_line.num = 0;

        return tok_line;
    }

    tokenized_line tok_line;
    tok_line.memory = INITIAL_BUFSIZE;
    tok_line.args = malloc(tok_line.memory * sizeof(char*));
    tok_line.num = 0;
    char* token;

    if(!tok_line.args){
        fprintf(stderr, "Mem allocation error.");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIMETER);
    while(token != NULL){
        tok_line.args[tok_line.num] = token;
        tok_line.num++;

        if(tok_line.num >= tok_line.memory){ // memory has run out!
            tok_line.memory *= 2;
            tok_line.args = realloc( // more space for args
                tok_line.args, 
                tok_line.memory * sizeof(char*)
            );

            if(!tok_line.args){
                fprintf(stderr, "Reallocation error.");
                exit(EXIT_FAILURE);
            }   
        }
        token = strtok(NULL, TOK_DELIMETER);
    }
    tok_line.args[tok_line.num] = NULL;

    tok_line.memory = tok_line.num + 1; 
    tok_line.args = realloc( // no waste of space :)
        tok_line.args,
        tok_line.memory * sizeof(char*)
    );

    return tok_line;
}