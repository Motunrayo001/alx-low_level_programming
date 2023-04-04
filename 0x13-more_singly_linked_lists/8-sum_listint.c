#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: a pointer to head of listint_t list
 * Return: 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int s = 0;

	while (head)
	{
		s += head->n;
		head = head->next;
	}
	return (s);
}
