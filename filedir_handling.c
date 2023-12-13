#include "main.h"




/**
 * path_chain - builds a linked-list of directory paths.
 * @dirs: the PATh variable, preferably.
 * Return: head of linked list, or NULL.
 */
path_list *path_chain(char *dirs)
{
	char *dir;
	path_list *node, *head;

	/* for now, assume dirs is not NULL */
	head = NULL;
	while ((dir = strtok(dirs, ":")) != NULL)
	{
		node->dir = dir;
		node->next = malloc(sizeof(path_list)); /* assume we can always ask and get. */
	}

	return (head);
}
