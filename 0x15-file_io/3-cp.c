#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close file(int f);

/**
 * create_buffer - allocate 1024 bytes for a buffer
 * @file: the name of the file
 * Return: pointer to the allocated new buffer
 */
char *create_buffer(char *file)
{
	buffer = malloc(sizeof(char) *1024);

	if (buffer == NULL)
	{
		dprintf(STDERR FILENO,
				"Error: Can't read to %s\n" file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - closes file
 * @f: file to be closed
 */
void close_file(int f)
{
	int a;

	a = close(f);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close f %d\n", f);
		exit(100);
	}
}
