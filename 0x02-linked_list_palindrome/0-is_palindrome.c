#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Determines if a linked list is a palindrome
 *
 * @head: pointer to head of a list
 *
 * Return: 1 if palindrome, 0 otherwise.
 */

int is_palindrome(listint_t **head)
{
	int count = 0;
	int index = 0;
	listint_t *strider = NULL;
	int *array = NULL;

	if (!head)
		return (0);
	if (!*head)
		return (1);
	strider = *head;
	while (strider)
	{
		strider = strider->next;
		count++;
	}
	if (count == 1)
		return (1);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (0);
	strider = *head;
	while (strider)
	{
		array[index] = strider->n;
		strider = strider->next;
		index++;
	}
	for (index = 0; index < (count / 2); index++)
	{
		if (array[index] != array[(count - 1) - index])
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}
