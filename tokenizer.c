#include "monty.h"
/**
 * tokenize - tokenizes a string
 * @buffer: the string to be tokenized
 * @delim: the delimiter or separator
 * Return: returns an array of strings or tokens
 */
char **tokenize(char *buffer, char *delim)
{
	char **tokens;
	char *token;
	int length;
	int i;

	tokens = malloc(sizeof(char *) * MAX_LEN);

	if (tokens == NULL)
	{
		perror("malloc failed");
		return NULL;
	}

	token = strtok(buffer, delim);
	i = 0;

	while (token != NULL && i < MAX_LEN)
	{
		length = strlen(token);
		tokens[i] = malloc(sizeof(char) * (length + 1));
		if (tokens[i] == NULL)
		{
			free_tokens(tokens);
			return (NULL);
		}
		strcpy(tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * free_tokens - frees an array of strings and the array itself
 * @tokens: the array of strings to be freed
 * Return: nothing
 */
void free_tokens(char **tokens)
{
	int i;

	i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
/**
 * reduce_spaces - removes excess spaces between words
 * @str: string to be operated on
 * Return: returns the reduced string
 */
char *reduce_spaces(char *str)
{
	int i, x;

	str = trim_whitespace(str);

	i = x = 0;

	while (str[i] != '\0')
	{
		if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
		{
			str[x++] = str[i];
		}
		i++;
	}
	str[x] = '\0';
	return (str);
}
/**
 * trim_whitespace - trims leading and trailing spaces
 * @str: string to be trimmed
 * Return: returns the string pointer
 *
 */
char *trim_whitespace(char *str)
{
	char *end;
	while (isspace((unsigned char)*str)) str++;
	if (*str == 0)
	{
		return str;
	}
	end = str + strlen(str) - 1;

	while (end > str && isspace((unsigned char)*end))
	{
		end--;
	}
	*(end+1) = '\0';

	return (str);
}

