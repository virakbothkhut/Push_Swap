/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:27:53 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 17:08:14 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		volume;

	if (ac < 2)
		return (0);
	stack_a = create_stack(ac, av);
	stack_b = NULL;
	input_checker(ac, av);
	if (is_sorted(stack_a))
		free_stack(&stack_a);
	volume = get_node_count(stack_a);
	if (volume <= 3)
		sort_three(&stack_a);
	else if (volume <= 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
