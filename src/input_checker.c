/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:27:46 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 16:28:20 by vkhut            ###   ########.fr       */
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
	int		i;
	char	**pointer;

	i = 0;
	if (ac == 2)
	{
		pointer = ft_split(av[1], ' ');
		split_ac(av[1], pointer);
	}
	else
	{
		while (av[i +1])
		{
			if (!validate_ac(av[i + 1], av))
				exit(1);
			i++;
		}
	}
}

void	split_ac(char *ac, char **pointer)
{
	int	i;

	i = 0;
	(void)ac;
	while (pointer[i])
	{
		if (!validate_ac(pointer[i], pointer))
		{
			free(pointer);
			exit(1);
		}
		i++;
	}
	free(pointer);
}

int	validate_ac(char *ac, char **pointer)
{
	long	num;

	if (!is_valid_num(ac))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = ft_atoi (ac);
	if (num < (long)INT_MIN || num > (long)INT_MAX || check_duplicate(pointer))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
