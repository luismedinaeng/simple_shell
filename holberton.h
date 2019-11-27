#ifndef S_SHELL
#define S_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


char **str_process(char **command, ssize_t r_b, int c);
int _atoi(char *s);
void change_dir(char *comm);
#endif
