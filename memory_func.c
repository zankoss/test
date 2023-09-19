#include "main.h"
/**
 * my_memset - Fill a block of memory with a specified value.
 * @ptr:   A pointer to the memory location to fill.
 * @value: The value to set in each byte of the memory block.
 * @num:   The number of bytes to set to the specified value.
 * Return: A pointer to the 'ptr' memory location.
 */
char *my_memset(char *ptr, char value, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		ptr[i] = value;
	return (ptr);
}
/**
 * _realloc - reallocates a block of memory.
 * @ptr: pointer to previous malloc.
 * @prev_size: size of old block.
 * @next_size: size of new block.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int next_size)
{
	char *k;

	if (!ptr)
		return (malloc(next_size));
	if (!next_size)
		return (free(ptr), NULL);
	if (next_size == prev_size)
		return (ptr);

	k = malloc(next_size);
	if (!k)
		return (NULL);

	prev_size = prev_size < next_size ? prev_size : next_size;
	while (prev_size--)
		k[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);
	return (k);
}
/**
 * str_of_str_free - frees a string of strings
 * @strstr: string of strings
 */
void str_of_str_free(char **strstr)
{
	char **s = strstr;

	if (!strstr)
		return;
	while (*strstr)
		free(*strstr++);
	free(s);
}
/**
 * free_nodes - frees all nodes.
 * @ptr: pointer to head.
 * Return: void.
 */
void free_nodes(node_t **ptr)
{
	node_t *node, *link_node, *head;

	if (!ptr || !*ptr)
		return;
	head = *ptr;
	node = head;
	while (node)
	{
		link_node = node->link;
		free(node->str);
		free(node);
		node = link_node;
	}
	*ptr = NULL;
}
/**
 * ptr_free_addr - free ptr and address.
 * @ptr: pointer.
 * Return: 1 (seccess), 0 (failure).
 */
int ptr_free_addr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}