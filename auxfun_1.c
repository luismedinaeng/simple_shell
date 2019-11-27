#include "holberton.h"

/**
 * _strdup - Duplicates the array inserted in other location
 * @str: String to duplicate
 *
 * Return: Pointer to the array.
 * Null if falls, or str is Null
 */
char *_strdup(char *str)
{
	char *s;
	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	s = (char *)malloc((len + 1) * sizeof(char));

	if (s != NULL)
		s = _strcpy(s, str);

	return (s);
}

/**
 * _strlen - return the length of a string
 * @s: Pointer to an string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copies the second to the first
 * parameter
 * @dest: The destination pointer
 * @src: The source pointer
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;

	do {
		*(dest + len) = *(src + len);
		len++;
	} while (*(src + len - 1) != '\0');
	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: The pointer to dest
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 - *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strstr - Locate the second string into
 * the first string
 * @haystack: String where to fnd the substring
 * @needle: the subtring to find
 *
 * Return: Pointer to the first occurence of the substring
 * NULL if any character is found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;

	while (haystack && haystack[i])
	{
		j = 0;
		while (needle && needle[j])
		{
			if (haystack[i + j] != needle[j])
				break;
			j++;
		}
		if (!needle[j])
			return (haystack + i);
		i++;
	}

	return (NULL);
}
