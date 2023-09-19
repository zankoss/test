#include "main.h"
/**
 * _strdup - Duplicate a string.
 * @str: The input string to duplicate.
 * Return: A pointer to the duplicated string or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--str;
	return (dup);
}
/**
 * _strlen - the length of a string.
 * @str: string to find length.
 * Return: length of string.
 */
int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}
/**
 * _strcpy - copie a string.
 * @dest: destination string.
 * @src: source string.
 * Return: destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _strcat - concatenates strings.
 * @dest: destination string.
 * @src: source string.
 * Return: destination.
 */
char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (tmp);
}
/**
 **_strchr - find character in a string.
 *@str: the string.
 *@chars: the characters.
 *Return: (NULL).
 */
char *_strchr(char *str, char chars)
{
	do {
		if (*str == chars)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}