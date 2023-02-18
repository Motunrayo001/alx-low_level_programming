#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main- print all numbers of base 16 in lowercase
 * Return: 0
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
