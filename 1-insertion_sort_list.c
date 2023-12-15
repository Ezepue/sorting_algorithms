#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm.
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		prev = current->prev;

		while (prev && temp->n < prev->n)
		{
			/* Swap temp and prev nodes */
			if (temp->next)
				temp->next->prev = prev;

			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->next = temp->next;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;

			print_list(*list);

			prev = temp->prev;
		}

		current = current->next;
	}
}
