#include "push_swap.h"

void	assign_index(t_stack **stack)
{
	t_stack	*current;
	int		size;
	int		*arr;
	int		i;

	current = *stack;
	size = get_node_count(*stack);
	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	sort_values(arr, size);
	assign_index_to_stack(stack, arr, size);
	free(arr);
}

void	sort_values(int *arr, int size)
{
	int	j;
	int	temp;
	int	min_indx;
	int	k;

	j = 0;
	while (j < size - 1)
	{
		min_indx = j;
		k = j + 1;
		while (k < size)
		{
			if (arr[k] < arr[min_indx])
				min_indx = k;
			k++;
		}
		if (min_indx != j)
		{
			temp = arr[j];
			arr[j] = arr[min_indx];
			arr[min_indx] = temp;
		}
		j++;
	}
}

void	assign_index_to_stack(t_stack **stack, int *arr, int size)
{
	t_stack	*current;
	int		i;

	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	process_bit(t_stack **stack_a, t_stack **stack_b, int bit)
{
	t_stack	*current;
	int		volume;
	int		i;

	i = 0;
	volume = get_node_count(*stack_a);
	while (i < volume)
	{
		current = *stack_a;
		if ((current->index >> bit) & 1)
		{
			rotate_a(stack_a);
		}
		else
		{
			push_b(stack_a, stack_b);
		}
		i++;
	}
}

void	push_back_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		push_a(stack_a, stack_b);
	}
}
