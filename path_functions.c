/**
 * build_path - Builds a single linked list with the paths of PATH
 *
 * Returns: The first element of the list
 */
env_var_t *build_path(void)
{
	env_var_t *head = NULL;
	char *variable;
	char *token;

	variable = _getenv("PATH");
	if (variable == NULL)
		return (NULL);

	token = strtok(variable, ":");
	while (token != NULL)
	{
		/* Add NULL guard */
		add_path_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(variable);
	return (head);
}


/**
 * add_path_end - Adds a new node at the end of a env_var_t list
 * @head: Head of the list
 * @n: Data to asign to the node
 *
 * Return: The addres of the new element
 */
env_var_t *add_path_end(env_var_t **head, const char *n)
{
	env_var_t *new_element;

	if ((*head) == NULL)
	{
		new_element = malloc(sizeof(env_var_t));
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
void free_path(env_var_t **head)
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
size_t print_path(const env_var_t *h)
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
