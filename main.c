#include "monty.h"
/**
 * main - main function
 * @argc: the number of commandline arguments
 * @argv: the array of commandline arguments
 * Return: returns nothing
 */
int main(int argc, char *argv[])
{
	int file_descriptor;
	int bytes_read;
	void *buffer;
	char **tokens;
	int i;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_descriptor = open(argv[1], O_RDONLY);

	if (file_descriptor == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buffer = (void *)malloc(MAX_LEN);

	if (buffer == NULL)
	{
		printf("Error: malloc failed");
		close(file_descriptor);
		exit(EXIT_FAILURE);
	}

	bytes_read = read(file_descriptor, buffer, MAX_LEN);

	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		printf("Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(buffer, "\n\t");
	if (tokens == NULL)
	{
		printf("Error in tokenization");
		free(buffer);
		close(file_descriptor);
		exit(EXIT_FAILURE);
	}

	while (tokens[i] != NULL)
	{
		get_func(tokens);
		i++;
	}

	free(buffer);
	free_tokens(tokens);
	close(file_descriptor);

	return (0);
}
