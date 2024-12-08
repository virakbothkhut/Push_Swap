/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:54:22 by vkhut             #+#    #+#             */
/*   Updated: 2023/12/18 21:08:58 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

static	int	check_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	int	check_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && check_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && check_digit(*str))
	{
		n = n * 10 + sign * (*str - '0');
		if (n > INT_MAX)
			return (INT_MAX);
		if (n < INT_MIN)
			return (INT_MIN);
		str++;
	}
	return (n);
}
