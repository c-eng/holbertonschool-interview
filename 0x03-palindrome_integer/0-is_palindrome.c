#include <stdio.h>
#include "palindrome.h"

/**
 * palindrome_deux - determines palindromeness of an integer
 *
 * @n: integer to determine
 * @count: digit count of integer
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int palindrome_deux(unsigned long n, int count)
{
	int i = 0;
	int darray[count];
	unsigned long digit = 10;

	for (; i < count; i++)
	{
		darray[i] = ((n % digit) / (digit / 10));
		digit = digit * 10;
	}
	for (i = 0; i < count / 2; i++)
	{
		if (darray[i] == darray[count - 1 - i])
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
	int digit_count = 1;
	unsigned long digit = 10;
	int output;

	while (digit < n)
	{
		digit = digit * 10;
		digit_count++;
	}
	if (digit_count == 1)
		return (1);
	if (n % 10 == 0)
		return (0);
	output = palindrome_deux(n, digit_count);
	return (output);
}
