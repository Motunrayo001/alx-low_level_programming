#include "main.h"
#include <stdio.h>

/**
 * print_array - function that prints n elements of an array of integers
 * @n: number of elements of the array to be printed
 * @a: Array of integers
 * Numbers must be separated by comma, followed by a space
 * Numbers should be displayed same order as they are stored in the array
 * Return: void
 */
void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		printf("%d", a[j]);
		if (j != (n - 1))
		{
			printf(", ");
		}
	}
	printf("\n");
}
