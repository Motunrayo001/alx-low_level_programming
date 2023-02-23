#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * followed by new line
 * @n: print from this number
 */
void print_to_98(int n)
{
	int i;
	int j;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i == 98)
			{
				printf("%d", n);
				printf('\n');
				break;
			}
			else
			{
				printf("%d, ", n);
			}
		}
	}
	for (n; n >= 98; n--)
	{
		if (n == 98)
		{
			printf("%d", n);
			printf("\n");
			break;
		}
		else
		{
			printf("%d, ", n);
		}
	}
}
