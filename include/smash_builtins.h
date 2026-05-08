#ifndef SMASH_BUILTINS_H
#define SMASH_BUILTINS_H

int smash_cd(char** args);
int smash_exit(char** args);
int smash_help(char** args);
int builtin_num();

// This is pretty new for me: an array of pointers to functions!
// I heard about it some time ago but never implemented it. :)
extern int (*builtin_func[]) (char**);

extern char* builtin_str[];

#endif 