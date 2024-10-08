/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:14:55 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/02 13:47:27 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//LIBS//
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>

//BUFFER//
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
//UTILS//
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t size, size_t c);
int		main(int argc, char **argv);
//*****//