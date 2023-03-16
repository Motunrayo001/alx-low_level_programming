#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: index
 * If the function fails, it should return NULL
 * if n is greater or equal to the length of s2
 * then use the entire string s2
 * if NULL is passed, treat it as an empty string
 * The returned pointer shall point to a newly allocated space in memory
 * which contains s1, followed by the first n bytes of s2
 * and null terminated
 * Return: char pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int s3 = 0, s4 = 0, b;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[s3] != '\0')
	{
		s3++;
	}
	while (s2[s4] != '\0')
	{
		s4++;
	}
	if (n > s4)
		n = s4;
	p = malloc((s3 + n + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	for (b = 0; b < s3; b++)
	{
		p[b] = s1[b];
	}
	for (; b < (s3 + n); b++)
	{
		p[b] = s2[b - s3];
	}
	p[b] = '\0';
	return (p);
}
