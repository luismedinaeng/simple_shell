#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char **_stru(char *stru);

int main(void)
{
	ssize_t bytes_read;
	size_t num_bytes;
	pid_t _pid;
	char *str, *strcp, *token, *tokens, *p_sign = "$ ";
	int status, exe, n = 0;
	char *input[10] = {};
	char **arg = NULL;

	num_bytes = 0;
	str = NULL;
	token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, p_sign, strlen(p_sign));

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
			tokens = strdup(str);
			token = strtok(tokens, " \n");
			n = 0;
			while (token != NULL)
			{
				input[n] = token;
				token = strtok(NULL, " \n");
				n++;
			}
			input[n] = NULL;
			/* execve (input[0], input, NULL); */

			_pid = fork();
			if (_pid == 0)
			{
				exe = execve(input[0], input, NULL);
				if (exe == -1)
				{
					perror("Error");
				}
				if (bytes_read = EOF)
					exit(0);
			}
			else if (_pid > 0)
			{
				wait(&status);
			}

		}
	}
}

/* char **_stru(char *stru) */
/* { */
/* 	char *intro[10] = {}; */
/* 	char *tkn, *tkns; */
/* 	int n = 0; */
/* 	tkns = strdup(stru); */
/* 	tkn = strtok(tkns, "\n "); */
/* 	while (tkn != NULL) */
/* 	{ */
/* 		intro[n] = tkn; */
/* 		tkn = strtok(NULL, "\n "); */
/* 		n++; */
/* 	} */
/* 	intro[n] = NULL; */

/* 	return(intro); */
/* } */
