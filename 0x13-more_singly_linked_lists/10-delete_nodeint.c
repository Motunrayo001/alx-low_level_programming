#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index
 * index of a listint_t linked list.
 * @head: pointer to the head of the listint_t list
 * @index: index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t, *copy = *head;
	unsigned int n;

	if (copy == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(copy);
		return (1);
	}
	for (n = 0; n < (index - 1); n++)
	{
		if (copy->next != NULL)
			copy = copy->next;
		else
			return (-1);
	}
	t = copy->next;
	copy->next = t->next;
	free(t);
	return (1);
}
