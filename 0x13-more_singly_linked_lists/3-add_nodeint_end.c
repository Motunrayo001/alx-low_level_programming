#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to listint_t
 * @n: add new integer to the new node
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a, *b = *head;

	a = malloc(sizeof(listint_t));
	if (a != NULL)
	{
		a->n = n;
		a->next = NULL;
	}
	else
		return (NULL);
	if (b == NULL)
		*head = a;
	else
	{
		while (b->next != NULL)
			b = b->next;
		b->next = a;
	}
	return (a);
}
