/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:14:40 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/02 13:53:26 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*space_memory;
	size_t	len_s1;
	size_t	len_s2;

	space_memory = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!space_memory)
		return (NULL);
	ft_strlcpy(space_memory, (char *)s1, len_s1 + 1);
	ft_strlcat(space_memory, s2, len_s1 + len_s2 + 1);
	return (space_memory);
}
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	int		i;

	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	i = 0;
	if (size <= dst_l)
		return (size + src_l);
	while (src[i] != '\0' && dst_l + i < size - 1)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
