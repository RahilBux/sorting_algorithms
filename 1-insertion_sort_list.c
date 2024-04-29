#include "sort.h"

/**
 * swap - Swaps two nodes in a list
 *
 * @h: Head of list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*h = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a linked list of integers
 *
 * @list: Pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap(list, &insert, i);
			print_list(*list);
		}
	}
}
