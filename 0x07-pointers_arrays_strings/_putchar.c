#include <unistd.h>

/**
 * _putchar - write the character c to std.out
 * @c: the character
 * Return: 1
 * error if -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
