#include "main.h"
#include <stdio.h>

/**
 * print_number- prints an integer
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('_');
		num = -num;
	}
	if ((num / 10) > 0)
	{
		print_number(num / 10);
	}
	_putchar((unsigned int)num % 10 + '0');
}
