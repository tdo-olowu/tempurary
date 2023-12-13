#include "main.h"

/**
 * tokenify - (verb) change a sentence into tokens.
 * @str: the string to tokenify.
 * Return: pointer to first string.
 */
char **tokenify(char *str, char *delim)
{
	/* guess a buffer size. if too small, reallocate. */
	/* some memry concerns here. wat if we can't get more memry? free and fail safely */
	size_t BUF = 64;
	size_t bufsize, i = 0;
	char *word = strtok(str, " ");
	char **tokens = malloc(BUF * sizeof(char*));

	for (i = 0, bufsize = BUF ; word != NULL ; ++i)
	{
		if (i == bufsize)
		{
			bufsize += BUF;
			tokens = realloc(tokens, bufsize * sizeof(char*));
		}
		tokens[i] = strdup(word);
		word = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}


/**
 * pathify - turn a command into a path.
 * @cmd: command
 * @pre: prefix.
 * Return: the concatenation of both.
 */
char *pathify(char *pre, char *cmd)
{
	/** assumes no NULL shenanigans */
	int i = strlen(pre);
	int j = strlen(cmd);
	int k;
	char *path = malloc((1 + i + j) * sizeof(char));

	for (k = 0 ; k < i ; ++k)
		path[k] = pre[k];
	for ( ; k < i + j ; ++k)
		path[k] = cmd[k - i];

	return (path);
}
