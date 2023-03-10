#include <unistd.h>
/**
 * main- _putchar.c - write the character c to std.out
 * Return: 1
 * error if -1 is returned.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
