/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:08 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 15:28:09 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*current;

	if (head == NULL)
		return ;
	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
	*head = NULL;
}

void	free_split_string(char **split_string)
{
	int	i;

	i = 0;
	while (split_string[i])
	{
		free(split_string[i]);
		i++;
	}
	free(split_string);
}

int	find_biggest(t_stack *head)
{
	int		biggest;
	t_stack	*pointer;

	if (!head)
		return (-1);
	pointer = head;
	biggest = pointer->value;
	while (pointer)
	{
		if (pointer->value > biggest)
		{
			biggest = pointer->value;
		}
		pointer = pointer->next;
	}
	return (biggest);
}

int	find_smallest(t_stack *head)
{
	int		smallest;
	t_stack	*current;

	smallest = head->value;
	current = head;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
		}
		current = current->next;
	}
	return (smallest);
}

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}
