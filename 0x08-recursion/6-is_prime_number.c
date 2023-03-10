#include "main.h"

/**
 * is_prime_number - function that returns 1
 * if the input integer is a prime number, otherwise return 0.
 * @n: integer
 * Return: 0 or 1
 */
int is_prime_number(int n)
{
	int i;

	i = 2;
	if (n < 2)
	{
		return (0);
	}
	if (n == 2)
	{
		return (1);
	}
	return (rec_n(n, i));
}

/**
 * rec_n - recursion loop
 * @n: number
 * @i: iterator
 * Return: 1 or 0
 */
int rec_n(int n, int i)
{
	if (i == n - 1)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	if (n % i != 0)
	{
		return (rec_n(n, i + 1));
	}
	return (0);
}
