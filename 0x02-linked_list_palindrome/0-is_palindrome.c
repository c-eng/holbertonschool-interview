#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * palindrome_pal - helper for is_palindrome
 *
 * @head: head of your pal
 * @count: how many pals you have
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int palindrome_pal(listint_t *head, int count)
{
	int index = 0;
	int array[count];
	listint_t *strider = head;

	while (strider)
	{
		array[index] = strider->n;
		strider = strider->next;
		index++;
	}
	for (index = 0; index < (count / 2); index++)
	{
		if (array[index] != array[(count - 1) - index])
			return (0);
	}
	return (1);
}

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
	listint_t *strider = NULL;

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
	return (palindrome_pal(*head, count));
}
