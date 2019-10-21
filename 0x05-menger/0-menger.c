#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "menger.h"

/**
 * m_print - menger print
 *
 * @x: x array
 * @y: y array
 * @level: array size
 *
 * Return: void
 */
void m_print(int *x, int *y, int level)
{
	int i = 0;

	for (; i < level; i++)
	{
		if (x[i] == 1 && y[i] == 1)
		{
			printf(" ");
			return;
		}
	}
	printf("#");
}

/**
 * m_tern_add - not ternary addition
 *
 * @array: array of not ternary values
 * @size: size of not ternary array
 *
 * Return: void
 */
void m_tern_add(int *array, int size)
{
	int i = 0;

	array[0]++;
	for (; i < size; i++)
	{
		if (array[i] > 2)
		{
			if (i == size - 1)
				return;
			array[i + 1]++;
			array[i] = 0;
		}
	}
}


/**
 * menger - 2d menger sponge print
 *
 * @level: levels of sponge
 *
 * Return: void
 */
void menger(int level)
{
	int *arrax, *array;
	int size, i, j;

	if (level < 0)
		return;
	arrax = malloc(sizeof(int) * level);
	array = malloc(sizeof(int) * level);
	if (!arrax || !array)
		return;
	for (i = 0; i < level; i++)
	{
		arrax[i] = 0;
		array[i] = 0;
	}
	size = (int)pow(3, level);
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			m_print(arrax, array, level);
			m_tern_add(arrax, level);
		}
		printf("\n");
		m_tern_add(array, level);
		for (i = 0; i < level; i++)
			arrax[i] = 0;
	}
}
