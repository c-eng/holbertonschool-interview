#include <stdio.h>
#include "palindrome.h"

/**
 * bam - Not pow, unsigned longs only
 *
 * @base: base number
 * @exp: exponent
 *
 * Return: base^exp
 */

unsigned long bam(unsigned long base, unsigned long exp)
{
	unsigned long result = 1;
	unsigned long i = 0;

	for (; i < exp; i++)
		result = result * base;
	return (result);
}

/**
 * palindrome_deux - determines palindromeness of an integer
 *
 * @n: integer to determine
 * @c: digit count of integer
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int palindrome_deux(unsigned long n, unsigned long c)
{
	unsigned long i = 0;
	unsigned long t = 10;

	for (i = 0; i < c / 2; i++)
	{
		if ((n % bam(t, i + 1)) / bam(t, i) ==
		    (n % bam(t, c - i)) / bam(t, c - (i + 1)))
			continue;
		else
			return (0);
	}
	return (1);
}

/**
 * is_palindrome - determines palindromeness of an integer
 *
 * @n: integer to determine
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long c = 1;
	unsigned long t = 10;
	int output;

	while (t <= n)
	{
		t = t * 10;
		c++;
	}
	if (c == 1)
		return (1);
	if (n % 10 == 0)
		return (0);
	output = palindrome_deux(n, c);
	return (output);
}
