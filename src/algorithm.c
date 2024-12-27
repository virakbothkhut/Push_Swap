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
	int	bit;

	assign_index(stack_a);
	bit = 0;
	max_bits = get_max_bits(stack_a);
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit);
		push_back_a(stack_a, stack_b);
		bit++;
	}
}

int	get_max_bits(t_stack **stack)
{
	t_stack	*current;
	int		max;
	int		max_bits;

	current = *stack;
	max = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	sort_three(t_stack **head)
{
	int	biggest;

	if (*head == NULL || (*head)->next == NULL)
		return ;
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
	int	volume;

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
	{
		swap_a(stack_a);
	}
}
