/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:17:18 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/14 14:17:18 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
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

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	space_memory = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!space_memory)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			space_memory[i] = s1[i];
	while (s2[++j] != '\0')
		space_memory[i + j] = s2[j];
	space_memory[i + j] = '\0';
	free(s1);
	return (space_memory);
}

void	*ft_calloc(size_t size, size_t c)
{
	char			*result;
	unsigned char	*str;
	size_t			i;

	result = malloc(size * c);
	if (!result)
		return (NULL);
	i = 0;
	str = (unsigned char *) result;
	while (i < size * c)
	{
		str[i] = 0;
		i++;
	}
	return (result);
}
