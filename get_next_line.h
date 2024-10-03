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
# define BUFFER_SIZE 1024
#endif

char *get_next_line(int fd);
//UTILS//
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
//*****//