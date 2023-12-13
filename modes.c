#include "main.h"


/**
 * interactive_mode - talk to shell via terminal.
 * Return: int for main to use.
 */
int interactive_mode(void);
{
	ssize_t bytes_rd;
	int eval = 1;
	pid_t cid;
	size_t len_inp = 0;

	char *user_inp = NULL;
	char **tokens;
	extern char **environ;

	do {
			prompt("(S) ");
			bytes_rd = readcmd(&user_inp, &len_inp, stdin);
			tokens = tokenify(user_inp, BLANK);
			if (strcmp(tokens[0], "exit") == 0)
				eval = -1;
			else
			{
				cid = fork();
				if (cid == 0)
				{
					tokens[0] = pathify("/bin/", tokens[0]);
					eval = execute(tokens[0], tokens, environ);
				}
			}
			cleanup(user_inp, tokens, NULL);
	} while (eval >= 0);

	return (EXIT_SUCCESS);
}


/**
 * file_mode - shell reads from a file.
 * @argc: argument count.
 * @argv: list of arguments passed to file.
 * @envp: pointer to environment
 * Return: int for main to use.
 */
int file_mode(int argc, char **argv, char **envp)
{
	(void)argc; (void)argv ; (void)envp;
	return (EXIT_FAILURE);
}
