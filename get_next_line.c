/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:14:25 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/02 13:52:22 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_line(int fd, char *line)
{
	char	*line;
	ssize_t	bytesread;

	while (!ft_strchr(line, '/n') && bytesread > 0)
	{
		line 
	}
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*bytesread;
	size_t		longline;

	longline = ft_strlen(get_line(fd, (char *)line) + 1);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = malloc(longline);
	line = get_line(fd, (char *)line); 
	line[longline] = 0;
	return (line);
}
