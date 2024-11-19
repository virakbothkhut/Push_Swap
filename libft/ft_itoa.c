/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:49 by vkhut             #+#    #+#             */
/*   Updated: 2023/12/18 16:17:24 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countlen(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	nbr;
	int			len;

	nbr = n;
	len = countlen(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		ptr[0] = '-';
	}
	else if (nbr == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	while (nbr)
	{
		ptr[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ptr);
}
