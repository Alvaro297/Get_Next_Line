/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:16:37 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/14 14:16:37 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line(char *line)
{
	size_t	i;
	size_t	n;
	char	*tline;

	i = 0;
	n = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tline = ft_calloc(sizeof(char), (ft_strlen(line) - i + 1));
	if (!tline)
		return (NULL);
	i++;
	while (line[i] != '\0')
		tline[n++] = line[i++];
	tline[n] = '\0';
	free(line);
	return (tline);
}

char	*full_line(char *tline)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!tline[j])
		return (NULL);
	while (tline[j] != '\n' && tline[j] != '\0')
		j++;
	line = ft_calloc(sizeof(char), j + 2);
	if (!line)
		return (NULL);
	while (tline[i] != '\n' && tline[i] != '\0')
	{
		line[i] = tline[i];
		i++;
	}
	if (tline[i] && tline[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*ft_get_line(int fd, char *tline)
{
	char	*line;
	ssize_t	bytesread;

	bytesread = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		bytesread = read(fd, line, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(tline);
			tline = NULL;
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
	static char	*tline[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tline[fd] = ft_get_line(fd, tline[fd]);
	if (!tline)
		return (NULL);
	line = full_line(tline);
	tline[fd] = ft_next_line(tline[fd]);
	if (line && *line == '\0')
	{
		free(line);
		free(tline[fd]);
		line = NULL;
		tline[fd] = NULL;
	}
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	argc = 1;
	fd = open(argv[argc], O_RDONLY);
	if (fd == -1)
    	perror("Error opening file");
	while ((i <= 6))
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