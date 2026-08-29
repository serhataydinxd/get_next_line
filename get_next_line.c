/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seraydin <seraydin@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:58:01 by seraydin          #+#    #+#             */
/*   Updated: 2026/08/29 14:50:23 by seraydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle(char **left)
{
	char	*temp;

	if (!(*left)[0])
	{
		free(*left);
		*left = 0;
		return (0);
	}
	temp = *left;
	*left = 0;
	return (temp);
}

static char	*return_line(char **left)
{
	char	*str;
	int		index;
	char	*temp;

	index = ft_strchr(*left, '\n');
	if (index == -1)
		return (handle(left));
	str = ft_strndup(*left, (index + 1));
	if (!str)
	{
		free(*left);
		*left = 0;
		return (0);
	}
	temp = ft_strndup(*left + index + 1, (int)(ft_strlen(*left) - index - 1));
	if (!temp)
	{
		free(str);
		free(*left);
		*left = 0;
		return (0);
	}
	free(*left);
	*left = temp;
	return (str);
}

static char	*read_line(int fd, char *left, char *buff)
{
	ssize_t	a_read;
	char	*temp;

	while (ft_strchr(left, '\n') == -1)
	{
		a_read = read(fd, buff, BUFFER_SIZE);
		if (a_read == -1)
		{
			free(left);
			return (0);
		}
		if (a_read == 0)
			break ;
		buff[a_read] = '\0';
		temp = ft_strjoin(left, buff);
		free(left);
		if (!temp)
			return (0);
		left = temp;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*left;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!left)
	{
		left = ft_strndup("", 0);
		if (!left)
			return (0);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free(left);
		return (0);
	}
	left = read_line(fd, left, buff);
	free(buff);
	if (!left)
		return (0);
	ret = return_line(&left);
	return (ret);
}
