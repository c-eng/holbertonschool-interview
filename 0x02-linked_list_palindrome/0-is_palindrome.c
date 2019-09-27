#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * llist_index_value - Retrieves node at an index in a linked list
 *
 * @head: head of linked list
 * @index: index to retrieve node from
 *
 * Return: node at list index, or NULL otherwise.
 */

listint_t *llist_index(listint_t *head, int index)
{
	int idx = 0;
	listint_t *strider = head;

	while (head && idx < index)
	{
		strider = strider->next;
		idx++;
	}
	if (idx == index && strider)
		return (strider);
	return (NULL);
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
	int index = 0;
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
	for (; index < (count / 2); index++)
	{
		if (llist_index(*head, index)->n !=
		    llist_index(*head, (count - 1) - index)->n)
		{
			return (0);
		}
	}
	return (1);
}
