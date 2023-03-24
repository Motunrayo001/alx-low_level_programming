#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers- function that prints numbers, followed by a new line
 * @n: number of integer passed
 * @separator: the string to be printed between numbers
 * @....: variable number of numbers to be printed
 * You are allowed to use printf
 * If separator is NULL, don’t print it
 * Print a new line at the end of your function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list num;
	unsigned int i;

	va_start(num, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(num, int));
		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(num);
}
