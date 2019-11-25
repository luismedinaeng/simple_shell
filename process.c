#include "holberton.h"
void *handle_error(char *comm, int _stat);
int print_number(int n);

char **str_process(char *command, ssize_t b_r)
{
	pid_t _pid;
	char *tkn, *tkns;
	char **input_bu;
	int status, exe, n = 0, ex_it, i = 0, m = 1;
	char **input = malloc(2 * sizeof(char*));
	if (input == NULL)
		return (NULL);

	tkn = strtok(command, " \n");
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

	if (n == 2)
	{
		ex_it = _atoi(input[1]);
		if (ex_it < 0)
		{
			write(STDERR_FILENO, "./shell: 1: exit: Illegal number: ", 34);
			write(STDERR_FILENO, input[1], strlen(input[1]));
			write(STDERR_FILENO, "\n", 1);
		}
		else if (ex_it > 255)
		{
			exit((ex_it % 256));
		}
		if (strcmp(input[0], "exit") == 0)
		{
			exit(ex_it);
			free(input);
		}
	}
	else
	{
		if(strcmp(input[0], "exit") == 0)
		{
			exit(ex_it);
			free(input);
		}
	}

	_pid = fork();
	if (_pid == 0)
	{
		exe = execve(input[0], input, NULL);
		if (exe == -1)
		{
			handle_error(input[0], m);
		}
		if (b_r = EOF)
			exit(0);
	}
	else if (_pid > 0)
	{
		wait(&status);
	}
	free(input);
}

void *handle_error(char *comm, int _stat)
{

	write(STDERR_FILENO, "./shell: ", 9);
	print_number(_stat);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comm, strlen(comm));
	write(STDERR_FILENO, ": not found\n", 12);
}

int print_number(int n)
{
	char conv;
	if (n / 10)
	{
		print_number(n / 10);
	}
	conv = ((n % 10) + '0');
	write(STDERR_FILENO, &conv, 1);
}
