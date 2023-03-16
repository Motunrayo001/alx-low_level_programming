#include "main.h"
#include <stdlib.h>

/**
 * array_range- function that creates an array of integers
 * The array created should contain all the values from min
 * (included) to max (included), ordered from min to max
 * If min > max, return NULL
 * If malloc fails, return NULL
 * @min: minimium
 * @max: maximium
 * Return: the pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *arr, b = 0, t = min;

	if (min > max)
		return (0);
	arr = malloc((max - min + 1) * sizeof(int));
	if (!arr)
		return (0);
	while (b <= max - min)
		arr[b++] = t++;
	return (arr);
}
