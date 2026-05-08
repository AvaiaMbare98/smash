#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // library for POSIX syscalls
#include "parser.h"
#include "executor.h"

char* read_line();
void smash_loop();

int main(int argc, char **argv){
    smash_loop();
    return 0;
}

void smash_loop(){
    char* line;
    tokenized_line args;
    int status;
    char cwd[1024]; // buffer for the current working directory

    do {
        if(getcwd(cwd, sizeof(cwd)) != NULL){
            printf("%s >", cwd);
        } else{
            perror("getcwd error");
            printf("> ");
        }

        line = read_line(); 
        args = arg_parser(line);
        status = process_executor(args.args);

        free(line);
        free(args.args);
    }while(status);

}

char* read_line(){
    char* line = NULL; 
    size_t buffer_size = 0;

    if(getline(&line, &buffer_size, stdin) == -1){
        if(feof(stdin)){
            exit(EXIT_SUCCESS);
        }
        else{
            exit(EXIT_FAILURE);
        }
    }
    return line;
}