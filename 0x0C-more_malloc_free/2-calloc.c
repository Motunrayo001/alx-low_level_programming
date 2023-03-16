#include "main.h"
#include <stdlib.h>

/**
 * _calloc- function that allocates memory for an array using malloc
 * The _calloc function allocates memory for an array of nmemb
 * elements of size bytes each and returns a pointer to the allocated memory
 * The memory is set to zero
 * If nmemb or size is 0, then _calloc returns NULL
 * If malloc fails, then _calloc returns NULL
 * @nmemb: number of element in the array
 * @size: bytes for each position in array
 * Return: pointer void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int b;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (b = 0; b < nmemb * size; b++)
		p[b] = 0;
	return (p);
}
