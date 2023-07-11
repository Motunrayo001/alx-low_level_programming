#include "main.h"

/**
 * main - copies the content of the file to another
 * @argc: number of arguments
 * @argv: arguments
 * if the number of argument is not the correct one, exit with code 97
 * print cp file_from file_to, followed by a new line, on the POSIX standard error
 * if file_to already exists, truncate it
 * if file_from does not exist, or if you can not read it, exit with code 98
 * if you can not create or if write to file_to fails, exit with code 99
 * if you can not close a file descriptor , exit with code 100
 * Permissions of the created file: rw-rw-r--.
 * If the file already exists, do not change the permissions
 * You must read 1,024 bytes at a time from the file_from to make less system calls
 * Use a buffer
 * You are allowed to use dprintf
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int from, to, rd, wrt;
	char *b;

	if (argc == 3)
		return (-1);
	else
	{
		dprintf(STDERR_FILENO,
				"Usage: cp file_from file_to\n");
		exit(97);
	}
	b = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, b, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(b);
			exit(98);
		}
		wrt = write(to, b, 1024);
		if (to == -1 || wrt == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(b);
			exit(99);
		}
		rd = read(from, b, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}
	for (; r > 0; )
		r--;
	free(b);
	close_file(from);
	close_file(to);
	return (0);
}

/**
 * read_file - allocates 1024 bytes
 * @file: file name to read
 * Return: the file
 */
char *read_file(char *file)
{
	char *f;

	f = malloc(sizeof(char) * 1024);
	if (f == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read %s\n", file);
		exit(98);
	}
	return (f);
}

/**
 * create_buffer - allocates 1024 bytes
 * @fb: file buffer name
 * Return: the newly allocated buffer
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
 * close_file - this closes file descriptors
 * @fd: the file descriptor
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);
	if (cl == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
