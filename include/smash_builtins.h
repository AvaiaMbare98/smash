#ifndef SMASH_BUILTINS_H
#define SMASH_BUILTINS_H

int smash_cd(char** args);
int smash_exit(char** args);
int smash_help(char** args);

// This is pretty new for me: an array of pointers to functions!
// I heard about it some time ago but never implented it. :)
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

#endif 