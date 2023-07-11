#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: NULL terminated string to add at the end of the file
 * Do not create the file if it does not exist
 * If text_content is NULL, do not add anything to the file.
 * If filename is NULL return -1
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wrt, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (-1);
	else
	{
		for (l = 0; text_content[l];)
			l++;
	}
	op = open(filename, O_WRONLY | O_APPEND);
	wrt = write(op, text_content, l);
	if (op == -1 || wrt == -1)
		return (-1);
	close(op);
	return (1);
}
