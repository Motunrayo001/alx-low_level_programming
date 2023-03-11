#include <stdio.h>
#include "main.h"

/**
 * main - program that prints the minimum number of coins
 * to make change for an amount of money.
 * @argc: count arguments
 * @argv: arguments
 * Return: 0 if success but 1 if it is error
 */
int main(int argc, char *argv[])
{
	int c;
	int coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	c = _atoi(argv[1]);
	while (c > 0)
	{
		coins++;
		if ((c - 25) >= 0)
		{
			c -= 25;
			continue;
		}
		if ((c - 10) >= 0)
		{
			c -= 10;
			continue;
		}
		if ((c - 5) >= 0)
		{
			c -= 5;
			continue;
		}
		if ((c - 2) >= 0)
		{
			c -= 2;
			continue;
		}
		c--;
	}
	printf("%d\n", coins);
	return (0);
}

/**
 * _atoi - Convert a string to an integer
 * @s: char array string
 * Description: Number in the string can be preceded by an infinite
 * number of characters
 * All -/+ signs before the number should be in consideration
 * If there are no numbers in the string, return 0
 * No need to check for overflow
 * Not allowed to hard-code special values
 * Return: first integer found in the string
 */
int _atoi(char *s)
{
	int a = 0;
	unsigned int b = 0;
	int c = 1;
	int d = 0;

	while (s[a])
	{
		if (s[a] == 45)
		{
			c *= -1;
		}
		while (s[a] >= 48 && s[a] <= 57)
		{
			d = 1;
			b = (b * 10) + (s[a] - '0');
			a++;
		}
		if (d == 1)
		{
			break;
		}
		a++;
	}
	b *= c;
	return (b);
}
