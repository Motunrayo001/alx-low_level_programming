#include "main.h"

/**
 * swap_int - A function that swaps the values of two integers
 * @a: the first integer to be swapped
 * @b: the second integer to be swapped
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
