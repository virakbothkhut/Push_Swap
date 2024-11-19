/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:53:27 by vkhut             #+#    #+#             */
/*   Updated: 2023/12/18 21:08:23 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destSize)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dest == NULL && destSize == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= destSize)
		return (src_len + destSize);
	else
		destSize -= dest_len;
	ft_strlcpy(dest + dest_len, src, destSize);
	return (dest_len + src_len);
}
