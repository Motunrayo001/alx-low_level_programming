#include "main.h"
#include <stdlib.h>

/**
 * strtow- function that splits a string into words.
 * @str: string
 * The function returns a pointer to an array of strings (words)
 * Each element of this array should contain a single word, null-terminated
 * The last element of the returned array should be NULL
 * Words are separated by spaces
 * If your function fails, it should return NULL
 * Return: NULL if str == NULL or str == ""
 */
char **strtow(char *str)
{
	int i, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);
	i = flag = len = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
			flag = 1;
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			flag = 0;
			len++;
		}
		i++;
	}
	len += flag == 1 ? 1 : 0;
	if (len == 0)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);
	util(words, str);
	words[len] = NULL;
	return (words);
}

/**
 * util - function to fetch words in an array
 * @words: the string of the array
 * @str: the string
 */
void util(char **words, char *str)
{
	int i, j, start, flag;

	i = j = flag = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
		{
			start = i;
			flag = 1;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			create_word(words, str, start, i, j);
			j++;
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		create_word(words, str, start, i, j);
}

/**
 * create_word - creates words and insert it in the array
 * @words: the array of the strings
 * @str: the string
 * @start: the starting index of the word
 * @end: the ending index of the word
 * @index: the index of the array
 */
void create_word(char **words, char *str, int start, int end, int index)
{
	int i, j;

	i = end - start;
	words[index] = (char *)malloc(sizeof(char) * (i + 1));
	for (j = 0; start < end; start++, j++)
		words[index][j] = str[start];
	words[index][j] = '\0';
}

