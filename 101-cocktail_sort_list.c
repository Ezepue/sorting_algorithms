#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *                      ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: The doubly linked list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}
