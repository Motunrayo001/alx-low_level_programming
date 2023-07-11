#include "main.h"

/**
 * create_file - create a file
 * @filename: the name of the file created
 * @text_content: NULL terminated string to write to the file
 * The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 * if the file already exists, truncate it
 * Return: 1 if successful or else -1 for failure
 */
int create_file(const char *filename, char *text_content)
{
	int f, wrt, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	else
		return (-1);
	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrt = write(f, text_content, l);
	if (f == -1 || wrt == -1)
		return (-1);
	close(f);
	return (1);
}
