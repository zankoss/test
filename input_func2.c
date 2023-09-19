#include "main.h"
/**
 * if_chaining - checks if chaining on last status.
 * @data: parameter.
 * @buffer: buffer.
 * @pos: position in buffer.
 * @start: starting position in buffer.
 * @length: length.
 * Return: Void.
 */
void if_chaining(data_t *data, char *buffer, size_t *pos, size_t start, size_t length)
{
	size_t a = *pos;

	if (data->data016 == 2)
	{
		if (data->data014)
		{
			buffer[start] = 0;
			a = length;
		}
	}
	if (data->data016 == 1)
	{
		if (!data->data014)
		{
			buffer[start] = 0;
			a = length;
		}
	}

	*pos = a;
}
/**
 * check_chaining - check if chars is chaining.
 * @data: parameter.
 * @buffer: buffer
 * @pos: addressof position.
 * Return: 1 (seccess), 0 (failure)
 */
int check_chaining(data_t *data, char *buffer, size_t *pos)
{
	size_t a = *pos;

	if (buffer[a] == '|' && buffer[a + 1] == '|')
	{
		buffer[a] = 0;
		a++;
		data->data016 = 1;
	}
	else if (buffer[a] == '&' && buffer[a + 1] == '&')
	{
		buffer[a] = 0;
		a++;
		data->data016 = 2;
	}
	else if (buffer[a] == ';')
	{
		buffer[a] = 0;
		data->data016 = 3;
	}
	else
		return (0);
	*pos = a;
	return (1);
}
/**
 * kill_data - initializes data_t.
 * @data: data struct address.
 */
void kill_data(data_t *data)
{
	data->data001 = NULL;
	data->data002 = NULL;
	data->data003 = NULL;
	data->data004 = 0;
}
/**
 * kill_data_struct - data_t struct clean.
 * @data: data address.
 * @secc: seccess if all data cleared.
 */
void kill_data_struct(data_t *data, int secc)
{
	str_of_str_free(data->data002);
	data->data002 = NULL;
	data->data003 = NULL;
	if (secc)
	{
		if (!data->data015)
			free(data->data001);
		if (data->data009)
			free_nodes(&(data->data009));
		if (data->data010)
			free_nodes(&(data->data010));
		if (data->data011)
			free_nodes(&(data->data011));
		str_of_str_free(data->data012);
			data->data012 = NULL;
		ptr_free_addr((void **)data->data015);
		if (data->data017 > 2)
			close(data->data017);
		_putchar(-1);
	}
}
/**
 * data_init - initializes data_t.
 * @data: data address.
 * @arg_v: argument.
 */
void data_init(data_t *data, char **arg_v)
{
	int i = 0;

	data->data008 = arg_v[0];
	if (data->data001)
	{
		data->data002 = string_to_word(data->data001, " \t");
		if (!data->data002)
		{

			data->data002 = malloc(sizeof(char *) * 2);
			if (data->data002)
			{
				data->data002[0] = _strdup(data->data001);
				data->data002[1] = NULL;
			}
		}
		for (i = 0; data->data002 && data->data002[i]; i++)
			;
		data->data004 = i;

		alias_to_token(data);
		var_to_token(data);
	}
}