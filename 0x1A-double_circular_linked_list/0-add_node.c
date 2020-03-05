#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - add node to the end of circular doubly linked list
 * @list: head of the DLL
 * @str: malloc'd string
 * Return: address of the new node or NULL
 */

List *add_node_end(List **list, char *str)
{
	List *new = NULL;

	if (!list)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!(new->str))
		return (NULL);
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(new->next)->prev = new;
		(new->prev)->next = new;
	}
	return (new);
}

/**
 * add_node_begin - add node to the beginning of circular doubly linked list
 * @list: head of the DLL
 * @str: malloc'd string
 * Return: address of the new node or NULL
 */

List *add_node_begin(List **list, char *str)
{
	List *new = NULL;

	new = add_node_end(list, str);
	if (!new)
		return (NULL);
	*list = new;
	return (new);
}
