#ifndef PARSER_H
#define PARSER_H

typedef struct tokenized_line{
    char** args; // the arguments of the command
    int args_count; // number of arguments
    int memory; // how much memory have we allocated?
} tokenized_line;

tokenized_line arg_parser(char* line);

#endif 