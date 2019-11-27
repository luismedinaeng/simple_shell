# SIMPLE SHELL
![enter image description here](https://cdn.pixabay.com/photo/2013/07/13/13/41/bash-161382_960_720.png)
This project aims to create a simple UNIX command interpreter, it will emulate different aspects from the bash shell
#SYNOPSIS
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

##Auxiliary Functions
The functions listed below were written by the authors in order to comply with
the project objectives:
 - **_strdup:** Duplicates the array inserted in other location
 - **_strlen:** Returns the lenght of a string
 - **_strcpy:** Copies a string
 - **_strcmp:** Compares two strings
 - **_strstr:** Locates the first string into the second string
 - **_strchr:** Locate the first ocurrence of a character
 - **str_concat:** Concatenates two strings