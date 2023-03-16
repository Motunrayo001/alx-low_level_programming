#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked- function that allocates memory using malloc
 * if malloc fails, the malloc_checked function should
 * cause normal process termination with a status value of 98
 * @b: unsigned integer
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
