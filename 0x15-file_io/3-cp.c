#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - copies content of the file to another
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > -1);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}


/**
 * read_file - read the file
 * @file: name of the file to that exist to read
 * Return: the file to read
 */
char *read_file(char *file)
{
	char *f;

	f = malloc(sizeof(char) * 1024);

	if (f == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from %s\n", file);
		exit(98);
	}
	return (f);
}

/**
 * create_buffer - Allocates 1024 bytes for a buffer
 * @fb: name of the file buffer to create
 * Return: pointer to the newly allocated buffer
 */
char *create_buffer(char *fb)
{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", fb);
		exit(99);
	}
	return (b);
}

/**
 * close_file - closes the file descriptors
 * @fd_value: file description the needs to be closed
 */
void close_file(int fd_value)
{
	int cl;

	cl = close(fd_value);
	if (cl == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", fd_value);
		exit(100);
	}
}
