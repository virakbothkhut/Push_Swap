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

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	temp = *stack;
	while (temp->next != tail)
		temp = temp->next;
	temp->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	r_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
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

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	prev = NULL;
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}
