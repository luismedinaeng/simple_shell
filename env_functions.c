#include "path.h"

/**
 * _genenv - Creates a copy of the environ variable to a new global variable
 *
 * Return: A double pointer variable that has the information of the environment
 */
char **_genenv(void)
{
	extern char **environ;
	int i = 0, count = 0;

	while (environ && environ[count])
		count++;

	env_var = malloc((count + 1) * sizeof(char *));
	if (env_var == NULL)
		return (NULL);

	while (i < count)
	{
		env_var[i] = _strdup(environ[i]);
		if (env_var[i] == NULL)
		{
			_free_env();
			return (NULL);
		}
		i++;
	}
	env_var[i] = NULL;

	return (env_var);
}

/**
 * _free_env - Frees the copy generated for environmental variables
 *
 * Return: Nothing
 */
void _free_env(void)
{
	int i = 0;

	while (env_var && env_var[i])
	{
		free(env_var[i]);
		env_var[i] = NULL;
		i++;
	}
	free(env_var);
	env_var = NULL;
}

/**
 * _printenv - Prints the environmental variables
 *
 * Return: Nothing
 */
void _printenv(void)
{
	char buffer[1024];
	int i, j, count;

	i = 0, count = 0;
	while (env_var && env_var[i])
	{
		j = 0;
		while (env_var[i][j])
		{
			if (count > 1024)
			{
				write(STDOUT_FILENO, buffer, 1024);
				count = 0;
			}
			buffer[count] = env_var[i][j];
			count++, j++;
		}
		if (count > 1024)
		{
			write(STDOUT_FILENO, buffer, 1024);
			count = 0;
		}
		buffer[count] = '\n';
		count++, i++;
	}
	write(STDOUT_FILENO, buffer, count);
}

/**
 * _getenv - Gets an environmental variable from the copy
 * @name: Name of the variable to get
 *
 * Return: The value of the variable to get created with malloc
 * NULL if the variable does not exist
 */
char *_getenv(char *name)
{
	unsigned int i = 0;
	char *strcp;

	while (env_var && env_var[i])
	{
		strcp = _strstr(env_var[i], name);
		if (strcp != NULL && strcp == env_var[i])
				return (_strchr(env_var[i], '=') + 1);
		i++;
	}
	return (NULL);
}
