#include "main.h"
/**
 * read_line - get input.
 * @data: parameter.
 * Return: bytes.
 */
ssize_t read_line(data_t *data)
{
	static char *buffer;
	static size_t i, j, length;
	ssize_t track = 0;
	char **buffer_ptr = &(data->data001), *ptr;

	_putchar(-1);
	track = input_cmd(data, &buffer, &length);
	if (track == -1)
		return (-1);
	if (length)
	{
		j = i;
		ptr = buffer + i;

		if_chaining(data, buffer, &j, i, length);
		while (j < length)
		{
			if (check_chaining(data, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			data->data016 = 0;
		}

		*buffer_ptr = ptr;
		return (_strlen(ptr));
	}

	*buffer_ptr = buffer;
	return (track);
}
/**
 * input_cmd - chained commands.
 * @data: data parameter.
 * @buffer: address of buffer.
 * @length: address of length variable.
 * Return: bytes.
 */
ssize_t input_cmd(data_t *data, char **buffer, size_t *length)
{
	ssize_t track = 0;
	size_t length_ptr = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, ctrl_c);
#if 0
		track = getline(buffer, &length_ptr, stdin);
#else
		track = nextline(data, buffer, &length_ptr);
#endif
		if (track > 0)
		{
			if ((*buffer)[track - 1] == '\n')
			{
				(*buffer)[track - 1] = '\0';
				track--;
			}
			data->data007 = 1;
			remp_sharp(*buffer);
			create_hist_list(data, *buffer, data->data018++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*length = track;
				data->data015 = buffer;
			}
		}
	}
	return (track);
}
/**
 * nextline - gets the next line of input from STDIN.
 * @data: parameter struct
 * @ptr: address of pointer to buffer.
 * @length: size of ptr.
 * Return: str.
 */
int nextline(data_t *data, char **ptr, size_t *length)
{
	static char buffer[1024];
	static size_t i, len;
	size_t b;
	ssize_t track = 0, str = 0;
	char *old_ptr = NULL, *new_ptr = NULL, *chars;

	old_ptr = *ptr;
	if (old_ptr && length)
		str = *length;
	if (i == len)
		i = len = 0;

	track = gets_line_buff(data, buffer, &len);
	if (track == -1 || (track == 0 && len == 0))
		return (-1);

	chars = _strchr(buffer + i, '\n');
	b = chars ? 1 + (unsigned int)(chars - buffer) : len;
	new_ptr = _realloc(old_ptr, str, str ? str + b : b + 1);
	if (!new_ptr)
		return (old_ptr ? free(old_ptr), -1 : -1);

	if (str)
		_strncat(new_ptr, buffer + i, b - i);
	else
		_strncpy(new_ptr, buffer + i, b - i + 1);

	str += b - i;
	i = b;
	old_ptr = new_ptr;

	if (length)
		*length = str;
	*ptr = old_ptr;
	return (str);
}
/**
 * gets_line_buff - read a buffer.
 * @data: parameter.
 * @buffer: buffer.
 * @i_size: size.
 * Return: track.
 */
ssize_t gets_line_buff(data_t *data, char *buffer, size_t *i_size)
{
	ssize_t track = 0;

	if (*i_size)
		return (0);
	track = read(data->data017, buffer, 1024);
	if (track >= 0)
		*i_size = track;
	return (track);
}
/**
 * remp_sharp - replaces '#' with '\0'
 * @buffer: address of string to.
 * Return: Always 0.
 */
void remp_sharp(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}
