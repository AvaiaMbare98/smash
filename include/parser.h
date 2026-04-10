#ifndef PARSER_H
#define PARSER_H

typedef struct command_line{
    char** args; // the arguments of the command
    int args_count; // number of arguments
    int memory; // how much memory have we allocated?
} command_line;

#endif 