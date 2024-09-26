#include "monty.h"
/**
 * push_to_stack - Pushes an element to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the script file
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * print_all - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: not used
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop_from_stack - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line no.
 */
void pop_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: Error: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = top_node->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(top_node);
}
/**
 * print_top - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: Error: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * swap_top_two - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */
void swap_top_two(stack_t **stack, unsigned int line_number)
{

	stack_t *top_node;
	stack_t *second_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Error: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	second_node = top_node->next;

	top_node->next = second_node->next;
	second_node->next = top_node;
	second_node->prev = NULL;
	top_node->prev = second_node;

	if (top_node->next != NULL)
	{
		top_node->next->prev = top_node;
	}

	*stack = second_node;
}
