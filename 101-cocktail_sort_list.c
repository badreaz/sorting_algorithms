#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked
 * list using cocktail shaker sort algorithm
 * @list: doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *h, *tmp;
	int swap = 1;

	while (swap)
	{
		swap = 0, h = *list;
		for (; h && h->next; h = h->next)
		{
			if (h->n > h->next->n)
			{
				if (h->prev)
					h->prev->next = h->next;
				tmp = h->prev;
				h->prev = h->next->prev;
				h->next->prev = tmp;
				tmp = h->next;
				h->next = h->next->next;
				h->next->next = tmp, swap = 1;
				print_list(*list);
			}
		}
		if (!swap)
			break;
		swap = 0;
		for (; h && h->prev; h = h->prev)
		{
			if (h->prev->n > h->n)
			{
				if (h->prev)
					h->prev->next = h->next;
				tmp = h->prev;
				h->prev = h->next->prev;
				h->next->prev = tmp;
				tmp = h->next;
				h->next = h->next->next;
				h->next->next = tmp, swap = 1;
				print_list(*list);
			}
		}
	}
}
