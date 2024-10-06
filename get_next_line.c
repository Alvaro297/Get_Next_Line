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

char	*full_line(char *tline)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(ft_strlen(tline));
	while (tline[i] != '\n')
	{
		line[i] = tline[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*get_line(int fd, char *tline)
{
	char	*line;
	ssize_t	bytesread;

	bytesread = 1;
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		bytesread = read(fd, line, BUFFER_SIZE);
		printf("Bytes leídos: %zd\n", bytesread);
		if (bytesread == -1)
		{
			printf("Error en 'read'\n");
			free(line);
			return (NULL);
		}
		line[bytesread] = '\0';
		printf("Contenido leído: %s\n", line);
		tline = ft_strjoin(tline, line);
	}
	free(line);
	return (tline);
}

char	*get_next_line(int fd)
{
	static char	*tline;
	char		*line;
	char		*aux;
	char		*bytesread;
	size_t		totallength;

	totallength = (tline ? ft_strlen(tline) : 0) + BUFFER_SIZE + 1;
	printf("Tamaño total calculado para la línea: %zu\n", totallength);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tline)
		return (NULL);
	tline = get_line(fd, tline);
	if (!tline)
		return (NULL);
	line = full_line(tline);
	tline = ft_strchr(tline, '\n');
	printf("Contenido leído: %s\n", tline);
	return (line);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((i <= 1))
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break;
		free(str);
		i++;
	}
	return (0);
}
