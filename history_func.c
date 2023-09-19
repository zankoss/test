#include "main.h"
/**
 * get_history - read history from file.
 * @data: parameter.
 * Return: count number line of history on success, 0 otherwise.
 */
int get_history(data_t *data)
{
	int i, end = 0, n_line = 0;
	ssize_t file_d, r_len, size_var = 0;
	struct stat st;
	char *buffer = NULL, *fvar = bring_hist(data);

	if (!fvar)
		return (0);

	file_d = open(fvar, O_RDONLY);
	free(fvar);
	if (file_d == -1)
		return (0);
	if (!fstat(file_d, &st))
		size_var = st.st_size;
	if (size_var < 2)
		return (0);
	buffer = malloc(sizeof(char) * (size_var + 1));
	if (!buffer)
		return (0);
	r_len = read(file_d, buffer, size_var);
	buffer[size_var] = 0;
	if (r_len <= 0)
		return (free(buffer), 0);
	close(file_d);
	for (i = 0; i < size_var; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			create_hist_list(data, buffer + end, n_line++);
			end = i + 1;
		}
	if (end != i)
		create_hist_list(data, buffer + end, n_line++);
	free(buffer);
	data->data018 = n_line;
	while (data->data018-- >= 4096)
		del_node_index(&(data->data010), 0);
	relist_history(data);
	return (data->data018);
}
/**
 * create_hist_list - access to a history linked list.
 * @data: arguments used to maintain.
 * @buffer: buffer
 * @n_line: the history.
 * Return: Always 0
 */
int create_hist_list(data_t *data, char *buffer, int n_line)
{
	node_t *node = NULL;

	if (data->data010)
		node = data->data010;
	add_node_end(&node, buffer, n_line);

	if (!data->data010)
		data->data010 = node;
	return (0);
}
/**
 * relist_history - relist the history of linked list.
 * @data: arguments used to maintain.
 * Return: data018.
 */
int relist_history(data_t *data)
{
	node_t *node = data->data010;
	int i = 0;

	while (node)
	{
		node->n = i++;
		node = node->link;
	}
	return (data->data018 = i);
}
/**
 * _his_display - displays the history list.
 * @info: arguments. Used to maintain.
 * Return: Always 0.
 */
int _his_display(data_t *data)
{
	listprint(data->data010);
	return (0);
}
/**
 * bring_hist - bring history file.
 * @data: parameter.
 * Return: atr of history file.
 */
char *bring_hist(data_t *data)
{
	char *buffer, *d;

	d = _getenv(data, "HOME=");
	if (!d)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(d) + _strlen("_history") + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, d);
	_strcat(buffer, "/");
	_strcat(buffer, "_history");
	return (buffer);
}