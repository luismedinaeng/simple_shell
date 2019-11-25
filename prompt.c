#include "holberton.h"

void sighandler(int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

int main(int argc, char *argv[])
{
	ssize_t bytes_read;
	size_t num_bytes;
	pid_t _pid;
	char *str, *p_sign = "$ ";
	char **intro;
	int i = 0;

	num_bytes = 0;
	str = NULL;

	if (argc > 1)
	{
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": 0: ", 5);
		write(STDERR_FILENO, "Can't open ", 11);
		write(STDERR_FILENO, argv[1], strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, p_sign, strlen(p_sign));

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
		{
			exit(-1);
		}
		else
		{
			intro = str_process(str, bytes_read);
			free(str);
		}
		str = NULL;
		free(str);
	}
}
