#include "lists.h"

/**
 * get_nodeint_at_index- returns the nth node of a listint_t linked list
 * @head: pointer of the head to listint_t list
 * @index: index of the node, starting at 0
 * Return: NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	for (n = 0; n < index; n++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
