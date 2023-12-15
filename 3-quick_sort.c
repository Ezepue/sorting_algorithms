#include "sort.h"

/**
 * partition_func - function that implements Lumoto partition scheme.
 * @arr: array
 * @start: 1st element
 * @end: last element
 * @arr_size: size
 * Return: index of swapped element
 */
int partition_func(int *arr, int start, int end, size_t arr_size)
{
	int index, counter, temp, pivot = arr[end];

	index = start - 1;

	for (counter = start; counter < end; counter++)
	{
		if (arr[counter] <= pivot)
		{
			index++;
			temp = arr[index];
			arr[index] = arr[counter];
			arr[counter] = temp;
			if (index != counter)
			print_array(arr, arr_size);
		}
	}
	temp = arr[index + 1];
	arr[index + 1] = arr[end];
	arr[end] = temp;
	if (end != (index + 1))
		print_array(arr, arr_size);
	return (index + 1);
}

/**
 * helper_func - Helper function for sort_func.
 * @arr: array
 * @start: start
 * @end: end
 * @arr_size: length of array
 * Return: void
 */
void helper_func(int *arr, int start, int end, size_t arr_size)
{
	int partition_index;

	if (start < end)
	{
		partition_index = partition_func(arr, start, end, arr_size);

		helper_func(arr, start, partition_index - 1, arr_size);
		helper_func(arr, partition_index + 1, end, arr_size);
	}
}

/**
 * sort_func - function
 *@sort_array: array to sort
 *@arr_size: size of array
 *Return: nothing.
 */
void sort_func(int *sort_array, size_t arr_size)
{
	if (arr_size < 2 || sort_array == NULL)
		return;
	helper_func(sort_array, 0, arr_size - 1, arr_size);
}
