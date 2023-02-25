#include "main.h"
#include <stdio.h>

/**
 * main- prints the numbers from zero to hundred
 * followed by a newline
 * but for multiple of three print Fizz instead of the number
 * and for multiple of five print Buzz
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3 == 0) && (i % 5 != 0))
		{
			printf("Fizz");
		}
		else if ((i % 5 == 0) && (i % 3 != 0))
		{
			printf("Buzz");
		}
		else if ((i % 3 == 0) && (i % 5 == 0))
		{
			printf("FizzBuzz");
		}
		else
		{
			printf("%d", i);
		}
		if (i != 100)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
