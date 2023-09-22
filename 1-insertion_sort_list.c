#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linkedd list of integers
 * in ascending order using the insertion sort algorithm.
 * @list: doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop = (*list)->next, *old, *new;

	while (loop)
	{
		old = loop->prev;
		new = loop->next;
		while (old && old->n > loop->n)
			old = old->next;
		if (!old)
		{
			(*list)->prev = loop;
			loop->next = *list;
			loop->prev = NULL;
			*list = loop;
		}
		else
		{
			old->next->prev = loop;
			loop->next = old->next;
			old->next = loop;
			loop->prev = old;
		}
		print_list(*list);
		loop = new;
	}
}
