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
	Node *arguments;
	char *token;
	int argc;
	char **argv;
	Node *current;
	extern char **environ;

	while (active)
	{
		printf("($) ");
		read = getline(&command, &len, stdin);	/*gets input and stores in buffer 'command' */
		if (read != -1) /* getline successful */
		{
			/* removes newline from command */
			if (command[read - 1] == '\n')
				command[read - 1] = '\0';
			/* tokenize command and arguments */
			arguments = NULL;
			token = strtok(command, " ");

			while (token)
			{
				arguments = append_argument(arguments, token);
				token = strtok(NULL, " ");
			}
			/*prepare arg array for execve */
			argc = 0;
			argv = NULL;
			current = arguments;

			while (current)
			{
				argv = (char **)realloc(argv, (argc + 2) * sizeof(char *));
				if (!argv)
				{
					perror("realloc args for execve");
					exit(EXIT_FAILURE);
				}
				argv[argc] = current->data;
				current = current->next;
				argc++;
			}
			argv[argc] = NULL; /*null terminate argument array*/
			/* check if command is valid and return path to executable */
			command_path = valid_command(command);
			if (command_path != NULL)
			{
				pid = fork();
				if (pid < 0) /* error in forking */
				{
					perror("fork");
				}
				else if (pid == 0) /* child process */
				{
					/* becomes the command with execve */
					execve(command_path, argv, environ);
					perror("execve"); /*only exicuted if execve fails */
					exit(EXIT_FAILURE);
				}
				else /* parent process */
				{
					wait(&status); /*waits for child to run command */
				}
			}
			else /* command_path = NULL, executable not found */
			{
				/*ERROR for no file or directory for command */
				printf("No such file or directory\n");
			}
		}
		else /*getline failed */
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}
		free(command); /*frees command after exicution */
		free_arguments(arguments);
		free(argv);
	}
	return (0);
}
