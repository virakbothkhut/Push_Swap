/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:35 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/20 21:32:36 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "push_stack.h"
#include <limits.h>
#include <ctype.h>
#include "../libft/libft.h"

void push_to_stack(t_stack *stack, t_node *node)
{
    if (stack->top == NULL)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        node->next = stack->top;
        stack->top = node;
    }
    stack->size++;
}

int handle_input_line(char *line, t_stack *stack_a, t_stack *stack_b)
{
    if (ft_strcmp(line, "ra") == 0)
    {
        ra(stack_a);
    }
    else if (ft_strcmp(line, "rb") == 0)
    {
        rb(stack_b);
    }
    else if (ft_strcmp(line, "rr") == 0)
    {
        rr(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "pb") == 0)
    {
        pb(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "pa") == 0)
    {
        pa(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "sa") == 0)
    {
        sa(stack_a);
    }
    else if (ft_strcmp(line, "sb") == 0)
    {
        sb(stack_b);
    }
    else if (ft_strcmp(line, "ss") == 0)
    {
        ss(stack_a, stack_b);
    }
    else
    {
        write(2, "Error: Invalid command\n", 23);
        return 1;
    }
    return 0;
}
void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}