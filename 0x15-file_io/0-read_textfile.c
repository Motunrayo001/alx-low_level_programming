#include "main.h"
#include <stdlib.h>

/**
 * read_textfile -reads a text file and prints it to the POSIX standard output
 * @letters: number of letters to read
 * @filename: text file for the reading
 * where letters is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t f;
	ssize_t w;
	ssize_t a;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	a = read(f, b, letters);
	w = write(STDOUT_FILENO, b, a);
	free(b);
	close(f);
	return (w);
}
