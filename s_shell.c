#include "shell.h"
/**
 * main- prompts user and runs given command
 *
 * Return: 0
 */
int main()
{
	char *command;
	size_t len = 0;
	ssize_t read;
	int active = 1;
	pid_t pid;
	int status;

	while (active)
	{
		printf("($) ");
		/* prompts for command */
		read = getline(&command, &len, stdin);	/*gets input and stores in buffer 'command' */
		if (read != -1) /* getline successful */
		{
		}
		else /*getline failed */
		{
		}
		free(command); /*frees command after exicution */
	}
}
