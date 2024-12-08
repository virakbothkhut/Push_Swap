/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:27:58 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 16:36:15 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

int	cal_rotates(t_stack *stack, int smallest)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (-1);
	while (stack)
	{
		if (stack->value == smallest)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	r_or_rr(t_stack **stack_a, int volume)
{
	int	smallest;
	int	smallpos;

	smallest = find_smallest(*stack_a);
	smallpos = cal_rotates(*stack_a, smallest);
	if (smallpos <= volume / 2)
	{
		while ((*stack_a)->value != smallest)
		{
			rotate_a(stack_a);
		}
	}
	else
	{
		while ((*stack_a)->value != smallest)
		{
			r_rotate_a(stack_a);
		}
	}
}
