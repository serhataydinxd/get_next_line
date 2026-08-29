/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:24:36 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/29 16:02:23 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t			a;
	unsigned char	ch;

	if (!s)
		return (-1);
	a = 0;
	ch = (unsigned char)c;
	while (s[a])
	{
		if ((unsigned char)s[a] == ch)
			return (a);
		a++;
	}
	return (-1);
}

char	*ft_strndup(char const *src, size_t n)
{
	char	*str;
	size_t	a;

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

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	a;
	size_t	b;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	a = 0;
	str[len] = '\0';
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b])
	{
		str[a + b] = s2[b];
		b++;
	}
	return (str);
}
