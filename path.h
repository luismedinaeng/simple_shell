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
void _printenv(void);
char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* Functions to work with the env var PATH */
env_path_t *build_path(void);
env_path_t *add_path_end(env_path_t **head, const char *n);
void free_path(env_path_t **head);
size_t print_path(const env_path_t *h);

/* Auxiliar functions of strings */
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);
char *_memcpy(char *dest, char *src, unsigned int n);


#endif
