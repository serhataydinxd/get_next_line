/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:24:36 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/26 18:12:28 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				a;
	unsigned char	ch;

	a = 0;
	ch = (unsigned char)c;
	while (s[a] && ((unsigned char)s[a] != ch))
		a++;
	if (s[a] || (!s[a] && ch == 0))
		return ((char *)&s[a]);
	return (0);
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
