#include "main.h"
/**
 * env_list - environ linked list
 * @data: Structure to maintain constant function prototype.
 * Return: Always 0
 */
int env_list(data_t *data)
{
	extern char **environ;
	node_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	data->data009 = node;
	return (0);
}
/**
 * _getenv - gets the value of an environ variable.
 * @data: arguments used to maintain.
 * @env_name: environ variable name.
 * Return: the value.
 */
char *_getenv(data_t *data, const char *env_name)
{
	node_t *node = data->data009;
	char *ptr;

	while (node)
	{
		ptr = if_starts(node->str, env_name);
		if (ptr && *ptr)
			return (ptr);
		node = node->link;
	}
	return (NULL);
}
/**
 * init_new_env2 - Initialize a new environment variable.
 * @data: arguments.
 * @varb: string environ variable.
 * @vstr: the string environ variable value.
 *  Return: Always 0
 */
int init_new_env2(data_t *data, char *varb, char *vstr)
{
	char *buffer = NULL;
	node_t *node;
	char *ptr;

	if (!varb || !vstr)
		return (0);

	buffer = malloc(_strlen(varb) + _strlen(vstr) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, varb);
	_strcat(buffer, "=");
	_strcat(buffer, vstr);
	node = data->data009;
	while (node)
	{
		ptr = if_starts(node->str, varb);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buffer;
			data->data013 = 1;
			return (0);
		}
		node = node->link;
	}
	add_node_end(&(data->data009), buffer, 0);
	free(buffer);
	data->data013 = 1;
	return (0);
}
/**
 * rm_new_env2 - unset environment.
 * @data: arguments.
 * @varb: string environ variable.
 * Return: 1 on delete, 0 otherwise.
 */
int rm_new_env2(data_t *data, char *varb)
{
	node_t *node = data->data009;
	size_t i = 0;
	char *ptr;

	if (!node || !varb)
		return (0);

	while (node)
	{
		ptr = if_starts(node->str, varb);
		if (ptr && *ptr == '=')
		{
			data->data013 = del_node_index(&(data->data009), i);
			i = 0;
			node = data->data009;
			continue;
		}
		node = node->link;
		i++;
	}
	return (data->data013);
}
/**
 * arr_cp_env - copy environ and returns the str array.
 * @data: arguments.
 * Return: Always 0.
 */
char **arr_cp_env(data_t *data)
{
	if (!data->data012 || data->data013)
	{
		data->data012 = str_of_list(data->data009);
		data->data013 = 0;
	}

	return (data->data012);
}