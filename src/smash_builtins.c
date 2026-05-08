#include "smash_builtins.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int (*builtin_func[]) (char**) = {
    &smash_cd,
    &smash_exit,
    &smash_help
};

char* builtin_str[] = {
    "cd",
    "exit",
    "help"
};

int smash_cd(char** args){
    if(args[1] == NULL){ 
        fprintf(stderr, "Expected argument to cd\n");
    }
    else{
        if(chdir(args[1]) != 0){ // If chdir does his job, it returns 0.
            perror("smash");
        }
    }

    return 1;
}

int smash_exit(char** args){
    return 0;
}


int smash_help(char** args){
    printf("-----------------------------------\n");
    printf("--       SMASH: SMAll SHell      --\n");
    printf("-----------------------------------\n");
    printf("  A lightweght shell written by    \n");
    printf("          Giorgio Grasso           \n\n");
    printf("These commands are built-ins:\n");

    for(int i = 0; i<builtin_num(); i++){
        printf("-> %s\n", builtin_str[i]);
    }

    printf("\nUse 'man <command>' for info on external programs.\n");
    
    return 1;
}

int builtin_num(){
    return sizeof(builtin_str) / sizeof(char *); 
}