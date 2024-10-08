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

char	*ft_next_line(char *line)
{
	size_t	i;
	size_t	n;
	char	*tline;

	i = 0;
	n = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (tline[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	tline = ft_calloc(sizeof(char), (ft_strlen(line) - i + 1));
	i++;
	while (line[i] != '\0')
	{
		tline[n] = line[i];
		n++;
		i++;
	}
	free(line);
	return (tline);
}

char	*full_line(char *tline)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(sizeof(char), ft_strlen(tline));
	while (tline[i] != '\n' && tline[i] != '\0')
	{
		line[i] = tline[i];
		i++;
	}
	if (tline[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return(line);
}

char	*get_line(int fd, char *tline)
{
	char	*line;
	ssize_t	bytesread;

	bytesread = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	if (!tline)
		tline = ft_calloc(1,1);
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		bytesread = read(fd, line, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(line);
			return (NULL);
		}
		line[bytesread] = '\0';
		tline = ft_strjoin(tline, line);
	}
	free(line);
	return (tline);
}

char	*get_next_line(int fd)
{
	static char	*tline;
	char		*line;
	char		*bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	tline = get_line(fd, tline);
	if (!tline)
		return (NULL);
	line = full_line(tline);
	tline = ft_next_line(tline);
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((i <= 4))
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break;
		free(str);
		i++;
	}
	return (0);
}*/
