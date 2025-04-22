#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - A function that sorts an array
 * of integers in ascending order
 * using the selection sort algorithm.
 *
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0, pmin = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		pmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pmin])
				pmin = j;
		}
		if (pmin != i)
		{
			temp = array[i];
			array[i] = array[pmin];
			array[pmin] = temp;
			print_array(array, size);
		}
	}
}
