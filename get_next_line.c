/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:58:01 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/26 21:47:23 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	dst_len;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size < 1)
		return (src_len + size);
	a = 0;
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (src_len + size);
	while (src[a] && (dst_len + a) < size - 1)
	{
		dst[dst_len + a] = src[a];
		a++;
	}
	dst[dst_len + a] = '\0';
	return (dst_len + src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	a;
	size_t			s_len;

	s_len = 0;
	if (!s)
		return (0);
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (0);
	if (len > s_len - start)
		len = s_len - start;
	a = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[start + a] && a < len)
	{
		str[a] = s[start + a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

static char	*ft_strndup(char const *src, int n)
{
	char	*str;
	int		a;

	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (0);
	a = 0;
	while (src[a] && a < n)
	{
		str[a] = src[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;
	ssize_t		a_read;
	size_t		a;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	while (!ft_strchr(buff, '\n'))
	{
		a_read = read(fd, buff, BUFFER_SIZE);
		if (a_read == -1)
			break ;
		buff[a_read] = '\0';
	}
	if (!ft_strchr(buff, '\n'))
		return (buff);
	str = ft_strndup(buff);
	buff = ft_strchr(buff, '\n');
	return (str);
}
