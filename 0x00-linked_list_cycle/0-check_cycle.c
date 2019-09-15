#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks a singly linked list for cycles.
 *
 * @list: pointer to the head of a singly linked list.
 *
 * Return: 1 if there is a cycle, 0 otherwise.
 */

int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;
	// test function input for validity
	if (!list || !(list->next))
		return (0);
	// assign strider variables to list head
	slow = list;
	fast = list->next;
	// traverse singly linked list with striders
	while (fast->next)
	{
		fast = fast->next;
		if (fast->next)
			fast = fast->next;
		else
			return (0);
		slow = slow->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
