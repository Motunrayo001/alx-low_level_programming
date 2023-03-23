#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the result of simple number
 * @argc: counts the argument
 * @argv: arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int n1, n2, result;
	char op;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);

	func = get_op_func(argv[2]);

	if (!func)
	{
		printf("Error\n");
		exit(99);
	}
	op = *argv[2];
	if ((op == '/' || op == '%') && n2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	result = func(n1, n2);
	printf("%d\n", result);
	return (0);
}
