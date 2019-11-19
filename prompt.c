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
	char *str, *strcp, *token, *tokens, *p_sign = "$ ";
	int status, exe, n = 0;
	char *input[10] = {};
	char **intro;

	num_bytes = 0;
	str = NULL;
	token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, p_sign, strlen(p_sign));

		signal(SIGINT, sighandler);

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
			/* tokens = strdup(str); */
			/* token = strtok(tokens, " \n"); */
			/* n = 0; */
			/* while (token != NULL) */
			/* { */
			/* 	input[n] = token; */
			/* 	token = strtok(NULL, " \n"); */
			/* 	n++; */
			/* } */
			/* input[n] = NULL; */
			intro = str_process(str, bytes_read);

			/* _pid = fork(); */
			/* if (_pid == 0) */
			/* { */
			/* 	exe = execve(intro[0], intro, NULL); */
			/* 	if (exe == -1) */
			/* 	{ */
			/* 		perror("Error"); */
			/* 	} */
			/* 	if (bytes_read = EOF) */
			/* 		exit(0); */
			/* } */
			/* else if (_pid > 0) */
			/* { */
			/* 	wait(&status); */
			/* } */

		}
	}
}
