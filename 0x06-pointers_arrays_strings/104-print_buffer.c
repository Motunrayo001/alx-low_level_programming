#include "main.h"
#include <stdio.h>

/**
 * print_buffer -  function that prints a buffer
 * The function must print the content of size bytes of the buffer pointed by b
 * The output should print 10 bytes per line
 * Each line starts with the position of the first byte
 * of the line in hexadecimal (8 chars), starting with 0
 * Each line shows the hexadecimal content (2 chars) of the buffer
 * 2 bytes at a time, separated by a space
 * Each line shows the content of the buffer.
 * If the byte is a printable character, print the letter, if not, print .
 * Each line ends with a new line \n
 * If size is 0 or less, the output should be a new line only \n
 * You are allowed to use the standard library
 * The output should look like the following example,
 * and formatted exactly the same way
 * @size: size of the buffer
 * @b: buffer
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i;
	int j;
	int o;

	o = 0;
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (o < size)
	{
		j = size - o < 10 ? size - 0 : 10;
		printf("%08x: ", o);
		for (i = 0; i < 10; i++)
		{
			if (i < j)
			{
				printf("%02x", *(b + o + i));
			}
			else
			{
				printf(" ");
			}
			if (i % 2)
			{
				printf(" ");
			}
		}

			for (i = 0; i < j; i++)
			{
				int c = *(b + o + i);

				if (c < 32 || c > 132)
				{
					c = '.';
				}
				printf("%c", c);
			}
			printf("\n");
			o += 10;
	}
}
