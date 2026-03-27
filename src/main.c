#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* read_line();
void smash_loop();

int main(int argc, char **argv){
    //smash_loop();
    return 0;
}

void smash_loop(){
    char* line;
    char** args;

    /*do {
        printf("> ");
        //Strumentopoli misteriosi per dopo
        //line = read_line(); 
        //args = arg_parser(line);

        free(line);
        free(args);
    }while(1);*/

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