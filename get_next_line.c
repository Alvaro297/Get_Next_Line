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

char	*get_line(int fd, char *tline)
{
	char	*line;
	ssize_t	bytesread;

	bytesread = 1;
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		line = malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		bytesread = read(fd, line, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(line);
			return (NULL);
		}
		line[bytesread] = '\0';
		tline = ft_strjoin(tline, line);
		free(line);
	}
	return (tline);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*bytesread;
	size_t		totallength;

	totallength = ft_strlen(line) + BUFFER_SIZE + 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(totallength);
	if (!line)
		return (NULL);
	line = get_line(fd, (char *)line);
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}

