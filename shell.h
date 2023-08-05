#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


typedef struct Node {
	char *data;
	struct Node *next;
} Node;

char *valid_command(const char *command);
Node *append_argument(Node *head, const char *argument);
void free_arguments(Node *head);

#endif
