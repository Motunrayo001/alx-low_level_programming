#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of listint_t
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t N = 0;

	while (h)
	{
		N++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (N);
}
