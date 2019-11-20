#include "holberton.h"

char **str_process(char *command, ssize_t b_r)
{
	pid_t _pid;
	char *tkn, *tkns;
	char **input_bu;
	int status, exe, n = 0;
	char **input = malloc(2 * sizeof(char*));
	if (input == NULL)
		return (NULL);

	tkns = strdup(command);
	tkn = strtok(tkns, " \n");
	n = 0;
	while (tkn != NULL)
	{
		if(n > 1)
		{
			input_bu = realloc(input[n], (n + 1) * sizeof(char*));
			if (input_bu == NULL)
				return NULL;
			input = input_bu;
		}
		input[n] = tkn;
		tkn = strtok(NULL, " \n");
		n++;
	}
	input[n] = NULL;

	if(strcmp(input[0], "exit") == 0)
		exit(0);

	_pid = fork();
	if (_pid == 0)
	{
		exe = execve(input[0], input, NULL);
		if (exe == -1)
		{
			perror(input[0]);
		}
		if (b_r = EOF)
			exit(0);
	}
	else if (_pid > 0)
	{
		wait(&status);
	}
	return(input);
}
