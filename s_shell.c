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
	char *command_path;

	while (active)
	{
		/* prompt for command if interactive */
		if (isatty(STDIN_FILENO) != 0)
			printf("($)");
		read = getline(&command, &len, stdin);	/*gets input and stores in buffer 'command' */
		if (read != -1) /* getline successful */
		{
			/* removes newline from command */
			if command[read - 1] == '\n'
				command[read - 1] = '\0';
			/* check if command is valid and return path to executable */
			command_path = valid_command(command);
			if (command_path =! NULL)
			{
				pid = fork();
				if (pid < 0) /* error in forking */
				{
				}
				else if (pid == 0) /* child process */
				{
					/* becomes the command with execve */
					execve(command_path, /*command line args*/, /*environment*/);
				}
				else /* parent process */
				{
					wait(status); /*waits for child to run command */
				}
			}
			else /* command_path = NULL, executable not found */
			{
				/*ERROR for no file or directory for command */
				printf("No such file or directory");
			}
		}
		else /*getline failed */
		{
		}
		free(command); /*frees command after exicution */
	}
}
