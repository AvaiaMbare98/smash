#ifndef LAUNCH_H
#define LAUNCH_H

// this function launch external programs, like ls, using fork/exec. 
// it won't be used to launch built-in programs.
int launch(char** args); 

#endif