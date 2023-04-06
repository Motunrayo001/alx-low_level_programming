#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _r - realocates the memory of array of pointers
 * @l: old list to append
 * @s: size of the new list
 * @n: new node to add to the list
 * Return: pointer to the new list
 */
listint_t **_r(listint_t **l, size_t s, listint_t *n)
{
	listint_t **n2;
	size_t a;

	n2 = malloc(s * sizeof(listint_t *));
	if (n2 == NULL)
	{
		free(l);
		exit(98);
	}
	for (a = 0; a < s - 1; a++)
		n2[a] = l[a];
	n2[a] = n;
	free(l);
	return (n2);
}

/**
 * free_listint_safe - function that frees a listint_t list
 * @head: double pointer to the beginning of the list
 * Return: number of nodes in the list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t a, n = 0;
	listint_t **l = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (n);
	while (*head != NULL)
	{
		for (a = 0; a < n; a++)
		{
			if (*head == l[a])
			{
				*head = NULL;
				free(l);
				return (n);
			}
		}
		n++;
		l = _r(l, n, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(l);
	return (n);
}
