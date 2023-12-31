#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);


void insertion_sort_list(listint_t **list);
void insert_node_at_correct_position(listint_t **list, listint_t *node);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);



void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void helper_func(int *arr, int start, int end, size_t len);
int partition_func(int *arr, int start, int end, size_t len);


#endif /* SORT_H */
