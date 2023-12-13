#include "main.h"

#define BLANK " "

/**
 * main - one-command shell.
 * this version is optimistic. assumes correct input.
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv, char **envp)
{
	if (isatty(STDIN_FILENO)) /* interactive mode */
		return (interactive_mode());
	return (file_mode(argc, argv, envp);
}
