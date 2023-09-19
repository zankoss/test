#include "main.h"
/**
 * _strncat - concatenates two strings using n bytes.
 *@dest: destination string.
 *@src: source string.
 *@n: the bytes to be used.
 *Return: concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}
/**
 * _strncpy - copies a string using n bytes.
 *@dest: the destination string.
 *@src: the source string.
 *@n: characters to be copied.
 *Return: concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}
/**
 * _strcmp - comparison of two strangs.
 * @s1: string
 * @s2: string
 * Return: - if s1 < s2, + if s1 > s2, 0 if s1 == s2.
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
/**
 * str_of_list - convert list to string.
 * @head: ptr first node.
 * Return: string.
 */
char **str_of_list(node_t *head)
{
	node_t *node = head;
	size_t a = length_of_list(head), b;
	char **str1;
	char *str;

	if (!head || !a)
		return (NULL);
	str1 = malloc(sizeof(char *) * (a + 1));
	if (!str1)
		return (NULL);
	for (a = 0; node; node = node->link, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(str1[b]);
			free(str1);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		str1[a] = str;
	}
	str1[a] = NULL;
	return (str1);
}
/**
 * str_change - change str.
 * @str1: addr str1.
 * @str2: string 2.
 * Return: 1 (seccess), 0 (failure).
 */
int str_change(char **str1, char *str2)
{
	free(*str1);
	*str1 = str2;
	return (1);
}