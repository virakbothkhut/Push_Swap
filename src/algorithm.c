/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:27:41 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 16:46:26 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	i;

	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		bucket_sort(stack_a, stack_b, i);
		i++;
	}
}

int	get_max_bits(t_stack *stack)
{
	int		max_value;
	t_stack	*current;
	int		bits;

	current = stack;
	max_value = 0;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	bits = 0;
	while ((max_value >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

void	bucket_sort(t_stack **stack_a, t_stack **stack_b, int bit_position)
{
	int	volume;
	int	i;

	i = 0;
	volume = get_node_count(*stack_a);
	while (i < volume)
	{
		if (((*stack_a)->value >> bit_position) & 1)
		{
			rotate_a(stack_a);
		}
		else
		{
			push_b(stack_a, stack_b);
		}
		i++;
	}
	while (*stack_b)
	{
		push_a(stack_a, stack_b);
	}
}

void	sort_three(t_stack **head)
{
	int	biggest;

	biggest = find_biggest(*head);
	if ((*head)->value == biggest)
	{
		rotate_a(head);
	}
	else if ((*head)->next->value == biggest)
	{
		r_rotate_a(head);
	}
	if ((*head)->value > (*head)->next->value)
	{
		swap_a(head);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		volume;

	volume = get_node_count(*stack_a);
	while (volume > 3)
	{
		r_or_rr(stack_a, volume);
		push_b(stack_a, stack_b);
		volume--;
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}
