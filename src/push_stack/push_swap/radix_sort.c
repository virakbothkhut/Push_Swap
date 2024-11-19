#include "push_swap.h"
#include "validation.h"

// Function to get the maximum value in stack A
int	get_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	max = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

// Function to calculate the number of bits required to represent the max value
int	get_num_bits(int max)
{
	int	bits;

	bits = 0;
	while (max)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	int max = get_max(stack_a);  
	int num_bits = get_num_bits(max); 
	for (int i = 0; i < num_bits; i++)
	{
		current = stack_a->top;
		printf("Before sorting pass %d:\n", i); 
		print_stack(stack_a->top);             
		print_stack(stack_b->top);              
		while (current)
		{
			if ((current->value >> i) & 1)
			{
				ra(&stack_a->top);
				printf("After ra (rotate) pass %d:\n", i);
				print_stack(stack_a->top);
			}
			else
			{
				pb(&stack_a->top, &stack_b->top);
				printf("After pb (push) pass %d:\n", i);
				print_stack(stack_a->top);
				print_stack(stack_b->top);
			}
			current = current->next;
		}
		printf("After sorting pass %d:\n", i);
		print_stack(stack_a->top);
		print_stack(stack_b->top);
		while (stack_b->top)
		{
			pa(&stack_a->top, &stack_b->top);
			printf("After pa (push back) pass %d:\n", i);
			print_stack(stack_a->top);
		}
	}
}
