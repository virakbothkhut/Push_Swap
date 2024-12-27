/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:08 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 15:28:09 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return (-1);
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return (-1);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	return (0);
}

int	rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (get_node_count(*stack) < 2)
		return (-1);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
	return (0);
}

void	swap_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}
