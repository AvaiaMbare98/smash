#include "executor.h"
#include "smash_builtins.h"
#include "smash_launch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int process_executor(char** args){

    if(args[0] == NULL)
        return 1; // empty string, return 1 to keep looping!


    
}