# Simple Shell
### Medellin 2019

## What is simple shell
*our version of simple shell using in C programming languages, building a sketch about of LINUX shell.

### hsh
```bash
#include <stdlib.h> 
#include <stdarg.h> 
#include "holberton.h"
``
/** *simple shell - our version of shell command interpreter* */

To initialize the simple shell just run ./hsh

There type an executable command and press enter, the simple shell should execute the command successfully.

### Description
Its a Unix shell created by Simon Parra and Tomas Mejia, students at Holberton school. the simple shell is a command processor that run in a text window, allowing the user to type commands. The idea is to replicate the exact same process of some of the commands as the actual shell processes. This project was completed as a part of the curriculum for Holberton School.

### Requirements

This was made it for running in a ```Ubuntu 14.04 LTS``` Linux enviroment.

### Installation

 - Clone the repository
 - Change directories into the repository
 - Compile with ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```
 - Run the shell in interactive mode with ```./hsh```
 - Or in non-interactive like ```echo "ls" | ./hsh```

### Usage
The directory contents should be compiled with the following command:

$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o hsh 
The program may be used, in any C language program, just execute the file hsh.

The way to write and execute command goes like this:

$ [WRITE COMMANDS]

Press enter

### Speacial Features to execute
 - cd: changes directory to the specified dir
 - help: prints the help page to understand more about the functions builtin
 - pwd: prints the current directory you are working on
 - env: prints the enviroment variables present in the shell
 - exit: Use this to exit properly from the simple shell

### C language standard functions used
 - write.
 - access 
 - chdir 
 - execve
 - exit
 - fork
 - free
 - getline
 - isatty
 - malloc
 - perror
 - signal
 - strtok
 - wait

 
### Own functions used
 - _realloc
 - free_grid
 - _strcmp
 - _strncat
 - _strcpy
 - _strcat
 - concat
 - getpath
 - psh_cd
 - psh_help
 - psh_env
 - psh_exit
 - psh_tokenize
 - psh_execution
 - psh_init
 - psh_loop
 - psh_read_line
 - _putchar
 - psh_execution
 - _cealloc
 - free_grid
 - getpath
 - getthepath
 - add_slash
 - access_check
 - _strncpy
 - complete_command

### Example

This happens when you run the command ```env``` after running this shell:

```bash
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
```

### Bugs

Bugs are unknown for this shell.

### Authors

Tomás Mejía | [Github](https://github.com/towasme/) | [Twitter](https://twitter.com/towasme)

Simón Parra | [Github](https://github.com/Simonster04/) | [Twitter](https://twitter.com/Simonster04)

### License

This project has no license. Just copy and enjoy.
