#include "shell.h"
/**
 * append_argument- adds arguments to linked list
 * @head: head of linked list
 * @argument: argument to be added
 *
 * Return: linked list
 */
Node *append_argument(Node *head, const char *argument)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node)
	{
		perror("malloc for arguments");
		exit(EXIT_FAILURE);
	}
	new_node->data = strdup(argument);
	new_node->next = NULL;
	if (!head)
	{
		return (new_node);
	}
	Node *current = head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
	return (head);
}

/**
 * free_arguments- frees linked list of arguments
 * @head: head of linked list
 */
void free_arguments(Node *head)
{
	while (head)
	{
		Node *temp = head;
		head = head->next;
		free(temp->data);
		free(temp);
	}
}
