#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n).
 * @head: a pointer to the address of head of the
 * listint_t list
 * Return: 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int r;

	if (*head == NULL)
		return (0);
	tmp = *head;
	r = (*head)->n;
	*head = (*head)->next;
	free(tmp);
	return (r);
}
