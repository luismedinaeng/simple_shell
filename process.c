#include "holberton.h"
void handle_error(char *comm, int _stat);
int print_number(int n);
void print_environ(void);

/**
 * str_process - Process and executes a command
 * @command: Command to execute
 * @b_r: Count of bytes inside commnad parameter
 * @c: Count of the command
 *
 * Return: Null pointers
 */
char **str_process(char **command, ssize_t b_r, int c)
{
	pid_t _pid;
	char *tkn, *tkns;
	char **input_bu;
	int status, exe, n = 0, ex_it = 0, i = 0;
	int s_m = (2 * sizeof(char *));
	char **input = malloc(2 * sizeof(char *));

	if (input == NULL)
		return (NULL);

	(void)i;
	(void)tkns;
	(void)b_r;
	tkn = strtok(*command, " \n\t");
	if (tkn == NULL)
	{
		free(input);
		return (NULL);
	}
	n = 0;
	while (tkn != NULL)
	{
		if (n >= 1)
		{
			input_bu = (char **)_realloc((char *)input, s_m, (n + 2) * sizeof(char *));
			if (input_bu == NULL)
				return (NULL);
			s_m = ((n + 2) * sizeof(char *));
			input = input_bu;
		}
		input[n] = tkn;
		tkn = strtok(NULL, " \n");
		n++;
	}
	input[n] = NULL;

	if (n >= 2)
	{
		ex_it = _atoi(input[1]);
		if (ex_it < 0)
		{
			write(STDERR_FILENO, "./shell: 1: exit: Illegal number: ", 34);
			write(STDERR_FILENO, input[1], _strlen(input[1]));
			write(STDERR_FILENO, "\n", 1);
			return (NULL);
		}
		if (ex_it > 255)
		{
			exit((ex_it % 256));
		}
		else if (_strcmp(input[0], "exit") == 0)
		{
			free(input), free(*command);
			exit(ex_it);
		}
	}
	else
	{
		if (_strcmp(input[0], "exit") == 0)
		{
			free(input), free(*command);
			exit(ex_it);
		}
		else if (_strcmp(input[0], "env") == 0)
		{
			print_environ();
			free(input);
			return (NULL);
		}
	}

	_pid = fork();
	if (_pid == 0)
	{
		exe = execve(input[0], input, environ);
		if (exe == -1)
		{
			handle_error(input[0], c);
		}
		/* if (b_r == EOF) */
		free(input), free(*command);
		_exit(0);
	}
	else if (_pid > 0)
	{
		wait(&status);
		free(input);
	}
	return (NULL);
}

/**
 * handle_error - Function that prints the info message of an error
 * @comm: Command which refers the error
 * @_stat: number of the command
 *
 * Return: Nothing;
 */
void handle_error(char *comm, int _stat)
{
	write(STDERR_FILENO, "./shell: ", 9);
	print_number(_stat);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comm, _strlen(comm));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * print_number - Prints a number on the standard output
 * @n: Number to print
 *
 * Return: The number printed
 */
int print_number(int n)
{
	char conv;

	if (n / 10)
	{
		print_number(n / 10);
	}
	conv = ((n % 10) + '0');
	write(STDERR_FILENO, &conv, 1);
	return (n);
}


/**
 * print_environ - Prints the environmental variables
 *
 * Return: Nothing
 */
void print_environ(void)
{
	int i = 0;

	while (environ && environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

}
