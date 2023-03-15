#include "main.h"
#include <stdlib.h>

/**
 * **alloc_grid- function that returns a pointer
 * to a 2 dimensional array of integers.
 * @width: width of the array
 * @height: height of the array
 * Each element of the grid should be initialized to 0
 * The function should return NULL on failure
 * Return: If width or height is 0 or negative
 */
int **alloc_grid(int width, int height)
{
	int **array, i, j;
	int len = width * height;

	if (len <= 0)
		return (NULL);
	array = (int **)malloc(sizeof(int *) * height);
	if (array == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		array[i] = (int *)malloc(sizeof(int) * width);
		if (array[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(array[i]);
			free(array);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			array[i][j] = 0;
	return (array);
}
