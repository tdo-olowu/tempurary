#include "main.h"

/**
 * execute - it sure is.
 * @cmd_path - path to cmd.
 * @argv - first arg is cmd_path by convention
 * @envp - pointer to env variables.
 */
int execute(char *cmd_path, char **argv, char **envp)
{
	int exe;

	exe = execve(cmd_path, argv, envp);
	if (exe < 0)
		perror("Couldn't execute");

	return (-1);
}
