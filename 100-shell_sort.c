#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Initialize the gap using Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* Start with the largest gap and reduce it */
	for (; gap > 0; gap /= 3)
	{
		/* Perform insertion sort for the current gap */
		for (i = gap; i < size; ++i)
		{
			temp = array[i];

			/* Move elements that are greater than temp to the right */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* Place temp in its correct position */
			array[j] = temp;
		}

		print_array(array, size);
	}
}
