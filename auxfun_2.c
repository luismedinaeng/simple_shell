#include "holberton.h"

/**
 * _strchr - Locate the first ocurrence of a
 * character
 * @s: Pointer to the string
 * @c: Character to look for
 *
 * Return: Pointer to the first occurence of the character.
 * NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		if (s[i + 1] == c)
			return (s + i + 1);
		i++;
	}

	return (0);
}

/**
 * str_concat - Concatenates two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Pointer to the array created with malloc
 * Null if falls, or str is Null
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	int len1, len2, len;

	len1 = s1 == NULL ? 0 : _strlen(s1);
	len2 = s2 == NULL ? 0 : _strlen(s2);
	len = len1 + len2;

	s = (char *)malloc((len + 1) * sizeof(char));

	if (s != NULL)
	{
		s = _strcpy(s, (s1 == NULL ? "\0" : s1));
		s = _strcpy(s + len1, (s2 == NULL ? "\0" : s2));
		s -= len1;
	}
	return (s);
}
