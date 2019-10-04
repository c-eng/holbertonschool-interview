#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 *
 * @head: head of the linked list
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *top = NULL;
	listint_t *bot = NULL;
	listint_t *bob = NULL;

	if (!head)
		return (0);
	if (!*head)
		return (1);
	top = *head;
	while (top)
	{
		bot = top;
		bob = bot->next;
		while (bob && bob->next)
		{
			bot = bob;
			bob = bob->next;
		}
		if (top->n == bob->n)
			;
		else
			return (0);
		free(bob);
		bot->next = NULL;
		if (top->next)
		{
			if (top->next->next)
				top = top->next;
			else
				break;
		}
		else
			break;
	}
	return (1);
}
