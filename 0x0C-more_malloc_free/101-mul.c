#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - multiple two positive numbers
 * @argc: count argument
 * @argv: argument
 * Usage: mul num1 num2
 * num1 and num2 will be passed in base 10
 * Print the result, followed by a new line
 * If the number of arguments is incorrect, print Error
 * followed by a new line, and exit with a status of 98
 * num1 and num2 should only be composed of digits.
 * If not, print Error, followed by a new line,
 * and exit with a status of 98
 * You are allowed to use more than 5 functions in your file
 * Return: int
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, carry, d1, d2, *result, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		for (i = 0; i <= len1 + len2; i++)
			result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		d1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			d2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (d1 * d2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}

/**
 * is_digit - check if there is non-digit char
 * @s: string to be evaluated
 * Return: 0 if there is non-digit, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - return the length of a string
 * @s: The string to get the length
 * Return: length of @s
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - handling errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}
