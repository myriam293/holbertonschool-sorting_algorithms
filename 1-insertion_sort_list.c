#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly
 * linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current_node = (*list)->next;

	while (current_node)
	{
		temp = current_node;
		current_node = current_node->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_t *left = temp->prev;
			listint_t *right = temp;

			left->next = right->next;
			if (right->next)
				right->next->prev = left;

			right->prev = left->prev;
			right->next = left;

			if (left->prev)
				left->prev->next = right;
			else
				*list = right;

			left->prev = right;

			print_list(*list);
		}
	}
}
