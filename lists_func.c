#include "main.h"
/**
 * add_node_end - add node to the end of the list.
 * @head: pointer to head of node.
 * @str: str of node.
 * @n: node index.
 * Return: length of list.
 */
node_t *add_node_end(node_t **head, const char *str, int n)
{
	node_t *node2, *node;

	if (!head)
		return (NULL);

	node = *head;
	node2 = malloc(sizeof(node_t));
	if (!node2)
		return (NULL);
	my_memset((void *)node2, 0, sizeof(node_t));
	node2->n = n;
	if (str)
	{
		node2->str = _strdup(str);
		if (!node2->str)
		{
			free(node2);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->link)
			node = node->link;
		node->link = node2;
	}
	else
		*head = node2;
	return (node2);
}
/**
 * del_node_index - deletes node at given index.
 * @head: pointer of the first node.
 * @n: index of node to delete.
 * Return: 1 on success, 0 on fail.
 */
int del_node_index(node_t **head, unsigned int n)
{
	node_t *node, *prev;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!n)
	{
		node = *head;
		*head = (*head)->link;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == n)
		{
			prev->link = node->link;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev = node;
		node = node->link;
	}
	return (0);
}
/**
 * node_with_prefix - node begin with prefix.
 * @node: pointer to list.
 * @prefix: prefix.
 * @chars: character next prefix.
 * Return: same node/null.
 */
node_t *node_with_prefix(node_t *node, char *prefix, char chars)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = if_starts(node->str, prefix);
		if (ptr && ((chars == -1) || (*ptr == chars)))
			return (node);
		node = node->link;
	}
	return (NULL);
}
/**
 * index_of_node - bring index of node.
 * @head: list head.
 * @node: node.
 * Return: index or -1.
 */
ssize_t index_of_node(node_t *head, node_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->link;
		i++;
	}
	return (-1);
}
/**length_of_list - length of linked list.
 * @head: pointer to first node
 * Return: size.
 */
size_t length_of_list(const node_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->link;
		i++;
	}
	return (i);
}