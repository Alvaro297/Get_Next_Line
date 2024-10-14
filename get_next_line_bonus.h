/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:18:49 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/14 14:18:49 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__BONUS_H
# define GET_NEXT_LINE__BONUS_H

//BUFFER//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//LIBS//
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *tline);
char	*full_line(char *tline);
char	*ft_next_line(char *line);
//UTILS//
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t num, size_t size);
//*****//
#endif