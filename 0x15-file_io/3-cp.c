#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the contents of a file to another file
 * @argc: count arguments
 * @argv: Arguments
 * You must read 1,024 bytes at a time from the
 * file_from to make less system calls
 * Use a buffer
 * You are allowed to use dprintf
 * if the number of argument is not the correct one, exit with code 97
 * and print Usage: cp file_from file_to, followed by a new line,
 * on the POSIX standard error
 * if file_to already exists, truncate it
 * if file_from does not exist, or if you can not read it, exit with code 98
 * and print Error: Can't read from file NAME_OF_THE_FILE,
* followed by a new line
* Return: 0
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	r = read(fd_from, buffer, 1024);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	w = write(fd_to, buffer, r);
	if (fd_to == -1 || w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	r = read(fd_from, buffer, 1024);
	fd_to = open(argv[2], O_WRONLY | O_APPEND);
	while (r > 0)
		;
	free(buffer);
	close_file(fd_from);
	close_file(fd_to);
	return (0);
}

/**
 * create_buffer - allocate 1024 bytes for a buffer
 * @f: the name of the file
 * Return: pointer to the allocated new buffer
 */
char *create_buffer(char *f)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't read to %s\n", f);
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
