#include "main.h"

/**
 * main- make alphabet x10 times
 * Return: 0
 */
void print_alphabet_x10(void)
{
	char c;
	int i;

	i = 0;

	while (i <= 9)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
