#include "main.h"

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: integer
 * Return: natural square root of a number
 */
int _sqrt_recursion(int n)
{

	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (real_sqrt_recursion(n, 0));
	}
}

/**
 * real_sqrt_recursion- recurses the natural square root of a number
 * @n: number to calculate the square root
 * @i: iterator
 * Return: resulting square root
 */
int real_sqrt_recursion(int n, int i)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}
	else if (i * i > n)
	{
		return (-1);
	}
	else if (i * i == n)
	{
		return (i);
	}
	else
	{
		return (real_sqrt_recursion(n, i + 1));
	}
}
