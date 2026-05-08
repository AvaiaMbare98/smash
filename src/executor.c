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

    
        for(int i = 0; i < builtin_num(); i++){
        if(strcmp(args[0], builtin_str[i]) == 0){
            return builtin_func[i](args);
        }
    }

    return smash_launch(args);
}