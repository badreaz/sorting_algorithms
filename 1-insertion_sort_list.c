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
		{
			old->next = loop->next;
			if (loop->next)
				loop->next->prev = old;
			loop->prev = old->prev;
			loop->next = old;
			if (old->prev)
				old->prev->next = loop;
			else
				*list = loop;
			old->prev = loop;
			old = loop->prev;
			print_list(*list);
		}
		loop = new;
	}
}
