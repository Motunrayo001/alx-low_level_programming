#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file
 * @filename: name of the file read
 * @letters: number of letters it should read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t f, wrt, rd;

	f = open(filename, O_RDONLY);
	if (f != -1)
	{
		b = malloc(sizeof(char) * letters);
		rd = read(f, b, letters);
		wrt = write(STDOUT_FILENO, b, rd);
	}
	else
		return (0);
	free(b);
	close(f);
	return (wrt);
}
