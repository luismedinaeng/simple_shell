#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	ssize_t bytes_read;
	size_t num_bytes;
	pid_t _pid;
	char *str, *strcp, *token, *tokens, *p_sign = "$ ";
	int status, exe, n = 0;
	char *input[10];

	num_bytes = 0;
	str = NULL;
	token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, p_sign, sizeof(p_sign));

		bytes_read = getline(&str, &num_bytes, stdin);

		if (bytes_read == EOF)
		{
			putchar('\n');
			exit(0);
		}
		if (bytes_read == -1)
		{
			exit(-1);
		}
		else
		{
			/* strcp = str; */
			/* token = strtok(strcp, " "); */
			/* while((token != NULL && n > 0) || n == 0) */
			/* { */
			/* 	input[n] = token; */
			/* 	n++; */
			/* 	token =strtok(NULL, " "); */
			/* } */

			tokens = strdup(str);
			token = strtok(tokens, " ");
			while (token != NULL)
			{
				input[n++] = strdup(token);
				token = strtok(NULL, " ");
			}

			exe = execve(input[0], input, NULL);
			/* _pid = fork(); */

			/* if (_pid == 0) */
			/* { */
			/* 	exe = execve(input[0], input, NULL); */
			/* } */
			/* else if (_pid > 0) */
			/* 	wait(&status); */
		}
	}
}
