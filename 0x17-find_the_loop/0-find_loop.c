#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 *
 * @head: head of linked list
 *
 * Return: address of the node where the loop starts or NULL for no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!head || !(head->next))
		return (NULL);
	slow = head;
	fast = head->next;
	while (fast->next)
	{
		fast = fast->next;
		if (fast->next)
			fast = fast->next;
		else
			return (NULL);
		slow = slow->next;
		if (slow == fast)
			return (slow);
	}
	return (NULL);
}
