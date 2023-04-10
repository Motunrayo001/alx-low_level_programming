#include "main.h"

/**
 * print_binary -  prints the binary representation of a number
 * You are not allowed to use arrays
 * You are not allowed to use malloc
 * You are not allowed to use the % or / operators
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int a, c = 0;
	unsigned long int b;

	for (a = 63; a >= 0; a--)
	{
		b = n >> 1;
		if (b & a)
		{
			_putchar('1');
			c++;
		}
		else if (c)
			_putchar('0');
	}
	if (!c)
		_putchar('0');
}
