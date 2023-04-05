#include "lists.h"

/**
 * print_listint_safe -  prints a listint_t linked list
 * This function can print lists with a loop
 * You should go through the list only once
 * If the function fails, exit the program with status 98
 * @head: pointer to the head of the listint_t list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t a, b = 0;
	const listint_t **l = NULL;

	while (head != NULL)
	{
		for (a = 0; a < b; a++)
		{
			if (head == l[a])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(l);
				return (b);
			}
		}
		b++;
		l = _rel(l, b, head);
		printf("-> [%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(l);
	return (b);
}

/**
 * _rel - reallocates memory for an array of pointers
 * @l: the old list
 * @size: size of the new list
 * @new: new node
 * Return: pointer to the new list
 */
const listint_t **_rel(const listint_t **l, size_t size, const listint_t *new)
{
	const listint_t **newl;
	size_t a;

	newl = malloc(size * sizeof(listint_t *head));
	if (newl == NULL)
	{
		free(l);
		exit(98);
	}
	for (a = 0; a < size - 1; a++)
		newl[a] = l[a];
	newl[a] = new;
	return (newl);
}
