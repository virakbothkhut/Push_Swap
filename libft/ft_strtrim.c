/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:02:52 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/27 22:33:32 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t char_check(char const *str, char const c)
{

	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static char *str_new(size_t n)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *trim;
    size_t start;
    size_t end;
    size_t i;

    if (!s1 || !set)
        return (NULL);

    start = 0;
    while (*(s1 + start) && char_check(set, *(s1 + start)))
        start++;

    end = ft_strlen(s1);
    while (end > start && char_check(set, *(s1 + (end - 1))))
        end--;

    if (start == end)
    {
        // If fully trimmed, return an empty string (no malloc needed)
        return (char *)malloc(1);  // Return a single byte for the empty string
    }

    trim = str_new(end - start);
    if (!trim)
        return (NULL);

    i = 0;
    while ((start + i) < end)
    {
        *(trim + i) = *(s1 + (start + i));
        i++;
    }
    *(trim + i) = '\0';
    return (trim);
}
