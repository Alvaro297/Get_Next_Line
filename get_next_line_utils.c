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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*space_memory;
	int		i;
	int		j;

	i = 0;
	j = 0;
	space_memory = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!space_memory)
		return (NULL);
	while (s1[i] != '\0')
	{
		space_memory[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		space_memory[i + j] = s2[j];
		j++;
	}
	space_memory[i + j] = '\0';
	return (space_memory);
}
