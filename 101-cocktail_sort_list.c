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
		for (h = *list, swap = 0; h && h->next; h = h->next)
		{
			if (h->n > h->next->n)
			{
				tmp = h->next;
				if (h->prev)
					h->prev->next = tmp;
				else
					*list = tmp;
				tmp->prev = h->prev, h->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = h;
				h->prev = tmp, tmp->next = h;
				h = tmp, swap = 1, print_list(*list);
			}
		}
		if (!swap)
			break;
		for (swap = 0; h && h->prev; h = h->prev)
		{
			if (h->prev->n > h->n)
			{
				tmp = h->prev, tmp->next = h->next;
				if (h->next)
					h->next->prev = tmp;
				h->prev = tmp->prev, h->next = tmp;
				if (tmp->prev)
					tmp->prev->next = h;
				else
					*list = h;
				tmp->prev = h, h = tmp, swap = 1;
				print_list(*list);
			}
		}
	}
}
