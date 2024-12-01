/* ************************************************************************** */
/*                                                                            */
/*                 	                                       :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:20:54 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/20 20:20:55 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"
#include "push_swap.h"
#include "utils.h"
#include "validation.h"
#include <limits.h>

int valid_integer(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[0] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int with_range(char *str)
{
	char *endptr;
	long n;

	n = strtol(str, &endptr, 10);
	if (*endptr != '\0' || n < INT_MIN || n > INT_MAX)
		return (0);
	if (n < INT_MIN || n > INT_MAX)
		return 0;
	return (1);
}

void append_stack(t_stack *stack, int *arr, int size)
{
	int i;
	t_node *new_node;

	i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			show_error();
		new_node->value = arr[i];
		new_node->next = stack->top;
		stack->top = new_node;
		if (stack->size == 0)
			stack->bottom = new_node;
		stack->size++;
		i--;
	}
}

int duplicates(t_stack *stack)
{
	if (stack->size < 2)
		return 0;
	t_node *current = stack->top;
	while (current && current->next)
	{
		if (current->value == current->next->value)
			return 1;
		current = current->next;
	}
	return (0);
}
