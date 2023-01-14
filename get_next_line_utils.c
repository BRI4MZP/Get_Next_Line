/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:17:59 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/13 23:39:39 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	cont;

	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	cont = -1;
	while (++cont < count * size)
		((char *)ret)[cont] = 0;
	return (ret);
}

int	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		++count;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	if ((char)c == 0)
		return (((char *)s + ft_strlen(s)));
	while (s[count++] != '\0')
	{
		if (s[count] == (char)c)
			return (((char *)s + count));
	}
	return (0);
}

char	*ft_insert(char *s1, char *s2)
{
	char	*dest;
	size_t	ca;
	size_t	cb;

	ca = -1;
	cb = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) +1, sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
		while (s1[++ca])
			dest[ca] = s1[ca];
	while (s2[cb])
		dest[ca++] = s2[cb++];
	free(s1);
	return (dest);
}
