/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:56:35 by vkhut             #+#    #+#             */
/*   Updated: 2023/12/18 14:58:44 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

// int	main(void)
// {
// 	char buffer[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
// 	printf("Before: ");
// 	for (size_t i = 0; i < sizeof(buffer); i++)
// 	{
// 		printf("%c ", buffer[i]);
// 	}
// 	printf("\n");
// 	ft_bzero(buffer, sizeof(buffer));
// 	printf("After: ");
// 	for (size_t i = 0; i < sizeof(buffer); i++)
// 	{
// 		printf("%c ", buffer[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
