#include "palindrome.h"

/**
 * is_palindrome - determines palindromeness of an integer
 *
 * @n: integer to determine
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long div = 10;
	unsigned long t = 0;
	unsigned long b = 0;

	while (n / div >= 10)
		div = div * 10;
	while (n > 9)
	{
		t = (n / div);
		b = (n % 10);
		if (t != b)
			return (0);
		n = (n % div) / 10;
		div = div / 100;
	}
	return (1);
}
