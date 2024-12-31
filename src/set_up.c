/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:03 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/09 12:43:10 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 2)
	{
		stack = create_stack_single(av[1]);
	}
	else
	{
		stack = create_stack_multi(ac, av);
	}
	return (stack);
}

void	add_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!*stack)
	{
		*stack = new_node;
	}
	else
	{
		current = *stack;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

int	get_node_count(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
	{
		return (1);
	}
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
