#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int f);

/**
 * create_buffer - allocate 1024 bytes for a buffer
 * @file: the name of the file
 * Return: pointer to the allocated new buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read to %s\n", file);
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
 * followed by a new line,
 * on the POSIX standard error
 * where NAME_OF_THE_FILE is the first argument passed to your program
 * if you can not create or if write to file_to fails, exit with code 99
 * and  Error: Can't write to NAME_OF_THE_FILE, followed by a new line
 * should be printed on the POSIX standard error
 * where NAME_OF_THE_FILE is the second argument passed to your program
 * if you can not close a file descriptor , exit with code 100
 * print Error: Can't close fd FD_VALUE, followed by a new line
 * on the POSIX standard error
 * where FD_VALUE is the value of the file descriptor
 * Permissions of the created file: rw-rw-r--.
 * If the file already exists, do not change the permissions
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int previous, new, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	previous = open(argv[1], O_RDONLY);
	r = read(previous, buffer, 1024);
	new = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (previous == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file%s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(new, buffer, r);
		if (new == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write%s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(previous, buffer, 1024);
		new = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buffer);
	close_file(previous);
	close_file(new);
	return (0);
}
