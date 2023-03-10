#include "main.h"

/**
 * _isdigit - check if the numbers sre from 0 to 9
 * @c: char needs to be checked
 * Return: 0 0r 1
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
