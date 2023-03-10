#include "main.h"

/**
 * *_memcpy - function that copies memory area
 * The _memcpy() function copies n bytes from memory area
 * src to memory area dest
 * @n: number of bytes
 * @src: source value
 * @dest: destination value
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int b = n;

	for (; a < b; a++)
	{
		dest[a] = src[a];
		n--;
	}
	return (dest);
}
