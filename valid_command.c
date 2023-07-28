#include "shell.h"
/**
 * valid_command- checks if command is valid and finds its path
 * @command: command to be checked
 *
 * Return: path of the command
 */
char *valid_command(const char *command)
{
	char *command_path = NULL;

	/* checks if command comtains '/', meaning it is already a path */
	if (strchr(command, '/') != NULL)
	{
		/* check if command path exists and is executable */
		if (access(command, X_OK) == 0)
		{
			command_path = strdup(command); /* return copy of command because it is already a path */
		}
		else
		{
			/* ERROR because command path is not valid or is not executable */
		}
	}
	else /*command is not a path already */
	{
		 /* check if command is in PATH environment variable
		 * create full path if the command and set to command_path
		 * or handle ERROR for command not found in PATH
		 */
	}
	return (command_path);
}
