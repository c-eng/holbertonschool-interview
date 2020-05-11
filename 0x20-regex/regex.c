#include "regex.h"

/**
 * compa - compares string
 * @s1: string 1
 * @s2: string 2, can have wilds
 * @wild: wildcard handling flag
 *
 * Return: 1 if true, 0 if false
 */

int compa(char const *s1, char const *s2, int wild)
{
	if (wild == 1)
	{
		if (s2[0] == '*')
			return (compa(s1, s2 + 1, 1));
		else if (s1[0] == s2[0])
			return (compa(s1, s2, 0));
		else if (s1[0] != '\0')
			return (compa(s1 + 1, s2, 1));
		else
			return (0);
	}
	else
	{
		if (s1[0] == '\0' && s2[0] == '\0')
			return (1);
		else if (s1[0] == s2[0])
		{
			if (compa(s1 + 1, s2 + 1, 0))
			{
				return (compa(s1 + 1, s2 + 1, 0));
			}
		}
		else if (s2[0] == '.' && s1[0] != '\0')
			return (compa(s1 + 1, s2 + 1, 0));
		else if (s2[0] == '*')
			return (compa(s1, s2, 1));
		else
			return (0);
	}
	return (0);
}

/**
 * regex_match - checks a pattern against a string
 * @str: string
 * @pattern: pattern
 *
 * Return: 1 if true, 0 if false
 */

int regex_match(char const *str, char const *pattern)
{
	return (compa(str, pattern, 0));
}
