#include "main.h"

/**
 * rev_string - function that reverses a string
 * @s: the string to be reversed
 * Return: void
 */
void rev_string(char *s)
{
	int index = 0, len = 0;
	char temp;

	while (s[index++])
		len++;
	for (index = len - 1; index >= len / 2; index--)
	{
		temp = s[index];
		s[index] = s[len - index - 1];
		s[len - index - 1] = temp;
	}
}
