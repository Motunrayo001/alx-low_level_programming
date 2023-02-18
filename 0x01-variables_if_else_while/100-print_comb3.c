#include <stdio.h>
#include <stdlib.h>
/**
 * main- program that prints all possible different combinations of two digits.
 * Return: 0
 */
int main(void)
{
	int a;
	int d = 0;

	while (d < 10)
	{
		a = 0;
		while (a < 10)
		{
			if (d != a && d < a)
			{
				putchar('0' + d);
				putchar('0' + a);

				if (a + d != 17)
				{
					putchar(',');
					putchar(' ');
				}
			}
			a++;
		}
		d++;
	}
	putchar('\n');
	return (0);
}
