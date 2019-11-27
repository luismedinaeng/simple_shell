#include "holberton.h"

/**
 * sighandler - Function that handles a signal
 * @sig: Code of signal
 *
 * Return: Nothing
 */
void sighandler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Entry point of application that emulates a simple shell
 * @argc: Count of arguments
 * @argv: Vector of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	ssize_t bytes_read;
	size_t num_bytes = 0;
	pid_t _pid;
	char *str = NULL, *p_sign = "$ ", **intro;
	int count = 1;

	(void)intro;
	(void)_pid;
	if (argc > 1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": 0: ", 5);
		write(STDERR_FILENO, "Can't open ", 11);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, p_sign, _strlen(p_sign));
		signal(SIGINT, sighandler);
		bytes_read = getline(&str, &num_bytes, stdin);
		if (bytes_read == EOF)
		{
			if (isatty(STDIN_FILENO))
				putchar('\n');
			free(str);
			exit(0);
		}
		if (bytes_read == -1)
			exit(-1);
		else
		{
			intro = str_process(&str, bytes_read, count);
			free(str);
		}
		str = NULL, count++, free(str);
	}
	return (0);
}
