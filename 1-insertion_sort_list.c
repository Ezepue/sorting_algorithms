#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		insert_node_at_correct_position(list, current);
		current = current->next;
	}
}

/**
 * insert_node_at_correct_position - Inserts a node at its correct position
 * in a doubly linked list.
 *
 * @list: The doubly linked list
 * @node: The node to be inserted at its correct position
 */
void insert_node_at_correct_position(listint_t **list, listint_t *node)
{
	listint_t *temp, *prev;

	temp = node;
	prev = node->prev;

	while (prev && temp->n < prev->n)
	{
		swap_nodes(list, temp, prev);

		temp = temp->prev;
		prev = temp->prev;
	}
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
	if (node1->next)
		node1->next->prev = node2;

	if (node2->prev)
		node2->prev->next = node1;
	else
		*list = node1;

	node2->next = node1->next;
	node1->prev = node2->prev;

	node1->next = node2;
	node2->prev = node1;

	print_list(*list);
}
