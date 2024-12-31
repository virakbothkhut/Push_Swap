/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:27:46 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/09 16:02:34 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_num(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	input_checker(int ac, char **av)
{
	if (ac < 2)
		return ;
	if (ac == 2)
	{
		handle_single_ac(av[1]);
	}
	else
	{
		handle_multi_ac(ac, av);
	}
}

void	check_ac(char **pointer)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while (pointer[i])
	{
		if (!validate_ac(pointer[i], pointer))
		{
			free_pointer(pointer);
			exit(1);
		}
		i++;
	}
	if (!valid)
	{
		free_pointer(pointer);
		exit(1);
	}
}

int	validate_ac(char *ac, char **pointer)
{
	long	num;

	if (!is_valid_num(ac))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = ft_atoi(ac);
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_duplicate(pointer))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
