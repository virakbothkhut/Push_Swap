/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:23:17 by vkhut             #+#    #+#             */
/*   Updated: 2023/12/18 19:23:23 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	length;
	size_t	index;

	index = 0;
	length = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * length + 1);
	if (res == NULL)
		return (NULL);
	while (index < length)
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
