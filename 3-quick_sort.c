#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the quick sort algorithm.
 * @array: array
 * @size: array's size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lower: lower
 * @higher: higher
 * @size: array's size
 * Return: i
 */

int partition(int *array, int lower, int higher, size_t size)
{
	int i = lower - 1, j = lower;
	int pivot = array[higher], temp = 0;

	for (; j < higher; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[higher])
	{
		temp = array[i + 1];
		array[i + 1] = array[higher];
		array[higher] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the quick sort algorithm.
 * @lower: lower
 * @higher: higher
 * @array: array
 * @size: array's size
 * Return: void
 */

void quick_s(int *array, int lower, int higher, size_t size)
{
	int pivot;

	if (lower < higher)
	{
		pivot = partition(array, lower, higher, size);
		quick_s(array, lower, pivot - 1, size);
		quick_s(array, pivot + 1, higher, size);
	}
}
