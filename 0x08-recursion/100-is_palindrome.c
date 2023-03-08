#include "main.h"

/**
 * is_palindrome -  function that returns 1
 * if a string is a palindrome and 0 if not.
 * @s: string
 * Return: 0 or 1
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (pal(s, len - 1));
}

/**
 * _strlen_recursion - size
 * @s: pointer to the string
 * Return: recursion
 */
int _strlen_recursion(char *s)
{
	if (!*s)
	{
		return (0);
	}
	return (1 + _strlen_recursion(++s));
}

/**
 * pal - palindrome
 * @s: pointer to the string
 * @p: position
 * Return: boolena
 */
int pal(char *s, int p)
{
	if (p < 1)
	{
		return (1);
	}
	if (*s == *(s + p))
	{
		return (pal(s + 1, p - 2));
	}
	return (0);
}
