/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:44 by euhong            #+#    #+#             */
/*   Updated: 2021/05/11 19:01:57 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_find_newline(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i + 1);
	return (0);
}

static char *ft_str_extend(char *str, char *buf, size_t  size)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(str);
	if (!(line = (char *)malloc(sizeof(char) * (len + size + 1))))
	{
		free(str);
		return (NULL);
	}
	while (++i < len)
		line[i] = *str++;
	while (++i < size)
		line[i] = *buf++;
	line[i] = '\0';
	free(str);
	return (line);
}

static char *ft_strdup_newline(char *str)
{
	char	*line;
	size_t	len;

	len = ft_find_newline(str);
	if (!(line = (char *)malloc(sizeof(char) * (len))))
	{
		free(str);
		return (NULL);
	}
	line[len--] = '\0';
	while (len-- >= 0)
		line[len] = str[len];
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	size_t		size;

	if (fd < 0 || !line || fd >= OPEN_MAX)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (!(str[fd] = ft_str_extend(str[fd], buf, size)))
			return (-1);
		if (ft_find_newline(buf))
		{
			if (!(*line = ft_strdup_newline(str[fd])))
				return (-1);
			return (1);
		}
	}
	if (size < 0)
		return (-1);
	return (0);
}
