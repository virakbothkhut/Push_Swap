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
	int	i;

	i = 0;
	if	(ac == 2)
	{
		char	**pointer;
		pointer = ft_split(av[1], ' ');
		while (pointer[i])
		{
			if (!is_valid_num(pointer[i]))
			{
				free(pointer);
				write(1, "Error\n", 6);
				exit(1);
			}
			long num;
			num = ft_atoi(pointer[i]);
			if	(num < (long)INT_MIN || num > (long)INT_MAX || check_duplicate(pointer))
			{
				free(pointer);
				write(1, "Error\n", 6);
				exit(1);
            }
			i++;
		}
		free(pointer);
    }
	else
    {
		while (av[i + 1])
        {
			if (!is_valid_num(av[i + 1]))
			{
				write(1, "Error\n", 6);
				exit(1);
            }
			long num;
			num = ft_atoi(av[i + 1]);
			if (num < (long)INT_MIN || num > (long)INT_MAX || check_duplicate(av))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			i++;
		}
	}
}
