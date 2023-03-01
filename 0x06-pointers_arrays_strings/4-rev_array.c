#include "main.h"

/**
 * reverse_array - reverse an array
 * @n: number of elements of the array
 * @a: array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i;
	int x;

	for (i = 0; i < n--; i++)
	{
		x = a[i];
		a[i] = a[n];
		a[n] = x;
	}
}
