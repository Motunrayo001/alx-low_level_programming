#include "main.h"

/**
 * *_strchr - function that locates a character in a string
 * @s: character of the string
 * @c: character
 * in the string s, or NULL if the character is not found
 * Return: pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	int a = 0;

	for (; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
		{
			return (&s[a]);
		}
	}
	return (0);
}
