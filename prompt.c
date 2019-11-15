#include <stdio.h>


int main(void)
{
	ssize_t bytes_read;
	size_t num_bytes;
	int i;
	char *string;

	printf("$ ");
	num_bytes = 0;
	string = NULL;
	bytes_read = getline(&string, &num_bytes, stdin);

	if (bytes_read == -1)
	{
		puts("Error.");
	}
	else
	{
		for(i= 0; string[i] != '\0'; i++)
			putchar(string[i]);
	}

	return 0;
}
