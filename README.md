# smash
Smash (SMAll SHell) is a lightweight Unix shell written in C. It's a personal project to explore OS concepts, POSIX system calls and memory management. 

## A quick note

I'm building this shell using various sources. At this stage of development, I am mostly relying on the [tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/) from Stephen Brennan for the core implementation.

I am also using Gemini as an interactive learning partner. So far, it has helped me: 
* Design the **architecture**, breaking down the shell into smaller modules
* Configure the **build system**, writing a TDD-ready Makefile to handle the Criterion testing framework