#include "sort.h"

/**
 * partition_func - function that implements Lumoto partition scheme.
 * @arr: array
 * @start: 1st element
 * @end: last element
 * @arr_size: size
 * Return: index of swapped element
 */
int partition_func(int *arr, int start, int end, size_t len)
{
	int i, j, swap, pivot = arr[end];

	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
			if (i != j)
			print_array(arr, len);
		}
	}
	swap = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = swap;
	if (end != (i + 1))
		print_array(arr, len);
	return (i + 1);
}

/**
 * helper_func - Helper function for sort_func.
 * @arr: array
 * @start: start
 * @end: end
 * @arr_size: length of array
 * Return: void
 */
void helper_func(int *arr, int start, int end, size_t len)
{
	int pi;

	if (start < end)
	{
		pi = partition_func(arr, start, end, len);

		helper_func(arr, start, pi - 1, len);
		helper_func(arr, pi + 1, end, len);
	}
}

/**
 * quick_sort - function
 *@arr: array to sort
 *@len: size of array
 *Return: nothing.
 */
void quick_sort(int *arr, size_t len)
{
	if (len < 2 || arr == NULL)
		return;
	helper_func(arr, 0, len - 1, len);
}
