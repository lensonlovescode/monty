#include "monty.h"
/**
 * main - main function
 * @argc: the number of commandline arguments
 * @argv: the array of commandline arguments
 * Return: returns nothing
 */
int main(int argc, char *argv[])
{
	int file_descriptor, bytes_read, i;
	void *buffer;
	char **tokens;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = (void *)malloc(MAX_LEN);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		close(file_descriptor);
		exit(EXIT_FAILURE);
	}
	bytes_read = read(file_descriptor, buffer, MAX_LEN);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	tokens = tokenize(buffer, "\n\t");
	check_null_tokens(tokens, file_descriptor, buffer);
	for (i = 0; tokens[i] != NULL; i++)
	{
		get_func(tokens);
	}
	free(buffer);
	free_tokens(tokens);
	close(file_descriptor);
	return (0);
}
/**
 * check_null_tokens - checks for null tokens
 * @tokens: the tokens array
 * @file_descriptor: file to close if tokens is null
 * @buffer: buffer to free //
 * Return: nothing
 */
void check_null_tokens(char **tokens, int file_descriptor, char *buffer)
{
	if (tokens == NULL)
	{
		fprintf(stderr, "Error in tokenization");
		free(buffer);
		close(file_descriptor);
		exit(EXIT_FAILURE);
	}
}
