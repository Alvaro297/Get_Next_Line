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


char *get_next_line(int fd);
//UTILS//
size_t	ft_strlen(const char *str);
//*****//