#include "main.h"


/**
 * prompt - prompt user for input
 * this version accepts custom prompt symbol.
 * @ps: prompt symbol.
 * Return: none.
 */
void prompt(char *ps)
{
	int len = strlen(ps);

	write(STDOUT_FILENO, ps, len);
}


/**
 * readcmd - read user input in interactive mode.
 * this is just a wrapper around getline.
 * i wrapped it just in case some nuance is needed.
 * @buffer: buffer to read into.
 * @len: length of buffer.
 * @filed: filedescriptor to read from.
 * Return: number of bytes read.
 */
ssize_t readcmd(char **buffer, size_t *len, FILE *filed)
{
	ssize_t bytes_read;

	bytes_read = getline(buffer, len, filed);
	return (bytes_read);
}
