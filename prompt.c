#include "holberton.h"

void sighandler(int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

int main(void)
{
	ssize_t bytes_read;
	size_t num_bytes;
	pid_t _pid;
	char *str, *p_sign = "$ ";
	char **intro;
	int i = 0;

	num_bytes = 0;
	str = NULL;

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
	}
}
