/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:40:52 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/13 05:07:07 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_rest(char *buffer)
{
	size_t	len;
	size_t	count;
	char	*changer;

	len = 0;
	while (buffer[len] != 0 && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
	{
		count = 1;
		while (buffer[++len])
			count++;
		changer = ft_calloc(count, sizeof(char));
		count = -1;
		while (buffer[len] != 0 && buffer[len] != '\n')
			changer[++count] = buffer[len];
		return (changer);
	}
	else
		return (NULL);
}

static char	*ft_get_line(char *buf)
{
	size_t	len;
	size_t	count;
	char	*changer;

	len = 0;
	if (!buf)
		return (NULL);
	while (buf[len] != 0 && buf[len] != '\n')
		len++;
	changer = (char *)ft_calloc(len + 2, sizeof(char));
	if (!changer)
		return (NULL);
	count = 0;
	while (buf[count] != 0 && buf[count] != '\n')
	{
		changer[count] = buf[count];
		count++;
	}
	if (buf[count] == '\n')
		changer[count] = '\n';
	return (changer);
}

// ssize_t read(int fildes, void *buf, size_t nbyte);
static char	*ft_main_read(int fd, char *buffer)
{
	char	*changer;
	int		reader;

	changer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!changer)
		return (0);
	reader = 1;
	while (!(ft_strchr(buffer, '\n')) && reader != 0)
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
	char		*get;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_main_read(fd, buffer);
	if (!buffer)
		return (0);
	get = ft_get_line(buffer);
	buffer = ft_get_rest(buffer);
	return (get);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/briveiro/Documents/Cursus/repodegetn/prueba.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}