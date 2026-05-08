# smash
Smash (SMAll SHell) is a lightweight Unix shell written in C. It's a personal project to explore OS concepts, POSIX system calls and memory management.

## Why Smash? 
Smash exists just as a learning project. Building Smash, I'm learning to:
* **Refresh** my C programming skills
* **Build** Unit and End-To-End tests using a TDD approach
* **Integrate** external frameworks such as Criterion
* **Write** bash scripts (I never wrote one before!)
* **Apply** POSIX system calls, building something practical on top of the OS theory I study at university
* **Use** generative AI as a learning partner in a responsible and constructive manner
* **Master** version control discipline with Git and GitHub, structuring a clean history through atomic commits rather than just "saving my work"

## A quick note

I'm building this shell using various sources. At this stage of development, I am mostly relying on the [tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/) from Stephen Brennan for the core implementation.

I am also using Gemini as an interactive learning partner. So far, it has helped me: 
* Design the **architecture**, breaking down the shell into smaller modules
* Configure the **build system**, writing a TDD-ready Makefile to handle the Criterion testing framework