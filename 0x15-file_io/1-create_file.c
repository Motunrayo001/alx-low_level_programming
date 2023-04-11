#include "main.h"

/**
 * create_file - Create a function that creates a file.
 * @filename:  the name of the file to create
 * @text_content: NULL terminated string to write to the file
 * The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 * Return: 1 on success, -1 on failure
 * file can not be created, file can not be written, write “fails”, etc…)
 */
int create_file(const char *filename, char *text_content)
{
	int f, w, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(f, text_content, l);
	if (f == -1 || w == -1)
		return (-1);
	close(f);
	return (1);
}
