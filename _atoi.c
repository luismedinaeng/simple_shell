#include "holberton.h"
/**
 *_atoi - convert string to an integer
 *@s: character
 *Return: int converted
 */
int _atoi(char *s)
{
	int n = 1;
	int m;
	int sign = 1;
	unsigned int num = 0;

	while (s[n] != '\0')
	{
		n++;
	}
	for (m = 0; m < n; m++)
	{
		if ((s[m] >= '0') && (s[m] <= '9'))
		{
			num = num * 10 + (s[m] - '0');
		}
		else if (s[m] == '-')
		{
			sign = sign * -1;
		}
		else if (num > 0)
		{
			break;
		}
	}
	return (num * sign);
}
