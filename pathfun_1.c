#include "holberton.h"

/**
 * build_path - Builds a single linked list with the paths of PATH
 * @env_var: Environmental variables
 *
 * Return: The first element of the list
 */
env_path_t *build_path(char **env_var)
{
	env_path_t *head = NULL;
	env_path_t *act;
	char *var_path, *token;

	var_path = _strdup(_getenv(env_var, "PATH"));
	if (var_path == NULL)
		return (NULL);

	token = strtok(var_path, ":");
	while (token != NULL)
	{
		/* Add NULL guard */
		act = add_path_end(&head, token);
		if (act == NULL)
		{
			free_path(&head);
			return (NULL);
		}
		token = strtok(NULL, ":");
	}
	free(var_path);
	return (head);
}

/**
 * add_path_end - Adds a new node at the end of a env_var_t list
 * @head: Head of the list
 * @n: Data to asign to the node
 *
 * Return: The addres of the new element
 */
env_path_t *add_path_end(env_path_t **head, const char *n)
{
	env_path_t *new_element;

	if ((*head) == NULL)
	{
		new_element = malloc(sizeof(env_path_t));
		if (new_element == NULL)
			return (NULL);

		new_element->value = strdup(n);
		if (new_element->value == NULL)
			return (NULL);

		new_element->next = NULL;

		*head = new_element;

		return (new_element);
	}
	else
	{
		return (add_path_end(&((*head)->next), n));
	}
}

/**
 * free_path - Frees a env_var_t list
 * @head: Head of list
 *
 * Return: Nothing
 */
void free_path(env_path_t **head)
{
	if (head == NULL)
		return;
	if (*head != NULL)
	{
		free_path(&((*head)->next));
		free((*head)->value);
		free(*head);
		*head = NULL;
	}
}

/**
 * print_path - Prints the elements of a env_var_t
 * @h: Head of the list
 *
 * Return: Number of nodes of the env_var_t
 */
size_t print_path(const env_path_t *h)
{
	if (h == NULL)
	{
		return (0);
	}
	else
	{
		printf("%s\n", h->value);
		return (1 + print_path(h->next));
	}
}

/**
 * check_file - Checks if a file exists on the PATH variable
 * @head: Head of the sinlgy linked list
 * @fl: File to check
 *
 * Return: A pointer to the string created with malloc if it find the path
 * NULL if does not find the path
 */
char *check_file(env_path_t *head, char *fl)
{
	char *full_path;
	char *part_path;
	struct stat sb;

	part_path = str_concat("/", fl);
	full_path = str_concat(head->value, part_path);
	free(part_path);

	if (stat(full_path, &sb) == 0)
	{
		return (full_path);
	}
	else
	{
		free(full_path);
		if (head->next == NULL)
			return (NULL);
		else
			return (check_file(head->next, fl));
	}
}
