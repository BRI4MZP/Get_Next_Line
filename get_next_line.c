/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:40:52 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/12 21:06:41 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t read(int fildes, void *buf, size_t nbyte);
static char	*ft_main_read(int fd, char *buffer)
{
	char	*changer;
	int		reader;

	changer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!changer)
		return (0);
	reader = read(fd, changer, BUFFER_SIZE);
	if (reader == -1)
		return (free(changer), NULL);
	while (!(ft_strchr(buffer, '\n')))
	{
		reader = read(fd, changer, BUFFER_SIZE);
		if (reader < 0)
		{
			free(buffer);
			free(changer);
			return (0);
		}
		changer[reader] = 0;
		buffer = ft_insert(buffer, changer);
	}
	free(changer);
	return (buffer);
}

// fd file descriptor es "El archivo que nos llega .txt"
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_main_read(fd, buffer);
	if (!buffer)
		return (0);
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/briamzp/Documents/Cursus/get_next_line/prueba.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}