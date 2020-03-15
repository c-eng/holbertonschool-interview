#include <stdlib.h>
#include "sort.h"

/**
 * max_int - max int in an int array
 * @array: array
 * @size: size of array
 * Return: max int in array
 */

int max_int(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Counting sort for Radix sort
 * @array: array to sort
 * @size: size of array
 * @digit: sig fig to sort by
 * Return: void
 */

void count_sort(int *array, size_t size, int digit)
{
	int *output = NULL;
	int count[10] = {0};
	size_t idx;

	output = malloc(sizeof(int) * size);
	for (idx = 0; idx < size; idx++)
		count[(array[idx] / digit) % 10]++;
	for (idx = 1; idx < 10; idx++)
		count[idx] += count[idx - 1];
	idx = size - 1;
	while (1)
	{
		output[count[(array[idx] / digit) % 10] - 1] = array[idx];
		count[(array[idx] / digit) % 10]--;
		if (idx == 0)
			break;
		idx--;
	}
	for (idx = 0; idx < size; idx++)
		array[idx] = output[idx];
	free(output);
}

/**
 * radix_sort - radix sort
 * @array: array to sort
 * @size: size of array to sort
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max, digit;

	if (!array || size < 2)
		return;
	max = max_int(array, size);
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		count_sort(array, size, digit);
		print_array(array, size);
	}
}
