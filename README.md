# SIMPLE SHELL
![enter image description here](https://cdn.pixabay.com/photo/2013/07/13/13/41/bash-161382_960_720.png)
This project aims to create a simple UNIX command interpreter, it will emulate different aspects from the bash shell
# SYNOPSIS
The simple shell provides a command line user interface, it can interact with
input provided by the user, displaying functions and executin programs. For
compilation we are using the folowwing libraries:
 - stdio.h
 - stdlib.h
 - unistd.h
 - string.h
 - sys/types.h
 - sys/stat.h
 - signal.h

## Auxiliary Functions
The functions listed below were written by the authors in order to comply with
the project objectives:
 - **_strdup:** Duplicates the array inserted in other location
 - **_strlen:** Returns the lenght of a string
 - **_strcpy:** Copies a string
 - **_strcmp:** Compares two strings
 - **_strstr:** Locates the first string into the second string
 - **_strchr:** Locate the first ocurrence of a character
 - **str_concat:** Concatenates two strings

## Compilation
The simple shell is compiled in GCC with the following script
```
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```
 - **-Wall** Consider all warnings including language specific warnings
 - **-Werror** Make all warnings into errors.
 - **-Wextra** Extra warnings suchs as Wstring-compare, -Woverride-init, etc.
 - **-pedantic** Issue all the warnings demanded by strict ISO C

## Execution
The simple shell can be called in both interative and non-interactive mode.

In the non-interactive mode, the shell will receive and run a script, for
this reason it will not interact with the user
```
$ echo "/bin/ls" | ./shell
prompt.c process.c _atoi.c README.md man_1_simple_shell
$
```

In the interactive mode, the shell will be executed and a prompt will appear
so the user can start typing commands and it will prompt again until the user
type the exit command or Ctr-D.
```
$ ./shell
$ /bin/ls
prompt.c process.c _atoi.c README.md man_1_simple_shell
```

## Commands with arguments

The simple shell handles commands with multiple arguments passed to programs
```
$ ls -l -a
total 108
-rw-rw-r--  1 vagrant vagrant  2016 Nov 27 01:30 #process.c#
drwxrwxr-x  3 vagrant vagrant  4096 Nov 27 16:52 .
drwxr-xr-x 15 vagrant vagrant  4096 Nov 26 14:39 ..
drwxrwxr-x  8 vagrant vagrant  4096 Nov 27 16:07 .git
-rw-rw-r--  1 vagrant vagrant  2091 Nov 27 16:52 README.md
-rw-rw-r--  1 vagrant vagrant   451 Nov 20 18:51 _atoi.c
-rw-rw-r--  1 vagrant vagrant   164 Nov 25 19:38 change_dir.c
-rw-rw-r--  1 vagrant vagrant   291 Nov 26 22:34 holberton.h
-rw-rw-r--  1 vagrant vagrant   846 Nov 27 15:52 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant  1681 Nov 26 22:33 process.c
-rwxrwxr-x  1 vagrant vagrant  9219 Nov 19 21:54 prompt
-rw-rw-r--  1 vagrant vagrant   965 Nov 26 22:34 prompt.c
-rwxrwxr-x  1 vagrant vagrant 13675 Nov 26 22:34 shell
-rw-rw-r--  1 vagrant vagrant    78 Nov 16 03:04 shell1.c
-rwxrwxr-x  1 vagrant vagrant  9849 Nov 19 13:48 str
-rwxrwxr-x  1 vagrant vagrant 17864 Nov 23 16:43 str_tok
$
```
## Exit
In order to exit The simple shell, the user can type the command *exit*, this
will terminate the program with an integer status. The shell handles End-of-file
conditions, it will exit when the user types Ctrl-D.
**Note:** The KeyStroke Ctrl-C will be ignored

## Flowchart
![enter image description here](https://ibb.co/tK5x6X3)

## Authors
Luis Medina, Fabio Gomez
