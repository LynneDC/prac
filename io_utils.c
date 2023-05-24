#include "main.h"

/**
 * _puts - writes string to stdout
 *
 * @str: string to be written
 *
 * Return: number of characters written
 */

int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (0);
}

/**
 * _putchar - write a charcter to standard out
 *
 * @c: the character to write
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
