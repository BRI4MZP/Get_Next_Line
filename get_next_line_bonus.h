/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:59:39 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/14 11:37:00 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
//static char	*ft_main_read(int fd, char *buffer);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(char *s, int c);
int			ft_strlen(char *s);
char		*ft_insert(char *s1, char *s2);
char		*cleaner(char *clean);
// static char	*ft_get_line(char *buf);
// static char	*ft_get_rest(char *buffer);

#endif