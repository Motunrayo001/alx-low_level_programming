#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the multiplication of two integers
 * @argc: count argument
 * @argv: Argument
 * Return: 0 if true, 1 if false
 */
int main(int argc, char *argv[])
{
	int a;
	int b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", a * b);
		return (0);
	}
	printf("Error\n");
	return (1);
}
