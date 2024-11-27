/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:35 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/27 22:28:57 by vkhut            ###   ########.fr       */
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
    char *trimmed_line;

    if (line == NULL || *line == '\0')
    { // Handle empty or NULL line
        return 1;
    }

    // Trim the line to remove unwanted spaces or newlines
    trimmed_line = ft_strtrim(line, " \t\n");

    // If trimming fails or the trimmed line is empty, return early
    if (trimmed_line == NULL || *trimmed_line == '\0')
    {
        free(line); // Free the original line if it's no longer needed
        return 1;
    }

    // Process the command
    if (ft_strcmp(trimmed_line, "ra") == 0)
    {
        ra(&stack_a->top);
    }
    else if (ft_strcmp(trimmed_line, "rb") == 0)
    {
        rb(&stack_b->top);
    }
    else if (ft_strcmp(trimmed_line, "rr") == 0)
    {
        rr(&stack_a->top, &stack_b->top);
    }
    else if (ft_strcmp(trimmed_line, "pb") == 0)
    {
        pb(&stack_a->top, &stack_b->top);
    }
    else if (ft_strcmp(trimmed_line, "pa") == 0)
    {
        pa(&stack_a->top, &stack_b->top);
    }
    else if (ft_strcmp(trimmed_line, "sa") == 0)
    {
        sa(&stack_a->top);
    }
    else if (ft_strcmp(trimmed_line, "sb") == 0)
    {
        sb(&stack_b->top);
    }
    else if (ft_strcmp(trimmed_line, "ss") == 0)
    {
        ss(&stack_a->top, &stack_b->top);
    }
    else
    {
        write(2, "Error: Invalid command\n", 23);
        free(trimmed_line); // Free the trimmed line before returning
        free(line);         // Free the original line too
        return 1;
    }

    // Free the memory for trimmed line after use
    free(trimmed_line); // Free the trimmed line after processing
    free(line);         // Free the original line after processing (if not already freed)

    return 0;
}

void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}
