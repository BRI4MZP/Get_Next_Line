/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:59:39 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/12 17:08:22 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
static char	*ft_main_read(int fd, char *buffer);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);
char		*ft_insert(char *s1, char *s2);
#endif