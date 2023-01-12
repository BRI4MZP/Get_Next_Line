/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:17:59 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/12 17:08:00 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	cont;

	ret = malloc(count * size);
	if (!ret)
		return (0);
	cont = -1;
	while (++cont < count * size)
		((char *)ret)[cont] = 0;
	return (ret);
}

int	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		++count;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	count;
	size_t	len;

	count = -1;
	len = ft_strlen(s);
	if ((char)c == 0)
		return (((char *)s + len));
	while (s[++count])
	{
		if (s[count] == (char)c)
			return (((char *)s + count));
	}
	return (0);
}

char	*ft_insert(char *s1, char *s2)
{
	char	*dest;
	size_t	c1;
	size_t	c2;

	c1 = -1;
	c2 = -1;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2), sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[++c1])
		dest[c1] = s1[c1];
	while (s2[++c2])
		dest[++c1] = s2[c2];
	return (dest);
}

