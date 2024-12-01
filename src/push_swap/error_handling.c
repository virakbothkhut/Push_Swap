/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:59 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/27 21:31:45 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"
#include "push_swap.h"
#include "utils.h"
#include "validation.h"

void show_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int *allocate_memory(int size)
{
	int *arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		show_error();
	}
	return (arr);
}
void convert_t_integer(int ac, char **av, int *arr)
{
	int i;

	i = 0;
	while (i < ac - 1)
	{
		arr[i] = atoi(av[i + 1]);
		i++;
	}
}

int validate_argc(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!valid_integer(av[i]) || !with_range(av[i]))
		{
			show_error();
			return (1);
		}
		i++;
	}
	return (0);
}

int handle_errors(int ac, char **av, t_stack *stack)
{
	int *arr;

	if (ac == 1)
		return (0);
	if (validate_argc(ac, av))
	{
		show_error();
		return (1);
	}
	arr = allocate_memory(ac - 1);
	if (!arr)
		show_error();

	convert_t_integer(ac, av, arr);
	append_stack(stack, arr, ac - 1);

	if (duplicates(stack))
	{
		free(arr);		   // Free allocated memory on error
		free_stack(stack); // Free stack memory
		show_error();
		return (1);
	}
	free(arr); // Free allocated memory when done
	return (0);
}
