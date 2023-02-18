#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main- print the last digit of the number stored in the variable n.
 * Description: Get a random number and print the number
 * Return: 0
 */
int main(void)
{
	int n;
	int last;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last = n % 10;
	if (last > 5)
	{
		printf("Last digits of %i is %i and is greater than 5\n", n, last);
	}
	else if (last == 0)
	{
		printf("Last digits %i is %i is 0\n", n, last);
	}
	else if (last < 6)
	{
		printf("Last digits of %i is %i and is less than 6 and not 0\n", n, last);
	}
	return (0);
}
