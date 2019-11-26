#ifndef PATH_H
#define PATH_H

/* Libraries to use */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct env_var - Struct of a singly linked list to manage the strings
 * @value: Value of the actual node
 * @next: Next item on the sinlgy linked list
 */
typedef struct env_path
{
	char *value;
	struct env_var *next;
} env_path_t;

/* Variable that has the environmental variables information */
char **env_var;

/* Functions to manage environmental variables */
char **_genenv(void);
void _free_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* Functions to work with the env var PATH */
env_var_t *build_path(void);
env_var_t *add_path_end(env_var_t **head, const char *n);
void free_path(env_var_t **head);
size_t print_path(const env_var_t *h);

/* Auxiliar functions of strings */
char *_strdup(char *str);
int _strlen(char *s);

#endif
