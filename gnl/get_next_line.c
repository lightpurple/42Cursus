/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:44 by euhong            #+#    #+#             */
/*   Updated: 2021/05/18 18:08:24 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_str_append(char *str, char *buf, int b_len)
{
	char	*res;
	int		s_len;

	s_len = 0;
	if (str)
		s_len = ft_strlen(str);
	if (!(res = (char *)malloc(sizeof(char) * (s_len + b_len + 1))))
		return (NULL);
	*res = '\0';
	if (str)
		res = ft_strncat(res, str, s_len);
	res = ft_strncat(res, buf, b_len);
	if (str)
		free(str);
	return (res);
}

static int	ft_split_linefid(char **str, char **line, int loc)
{
	char	*temp;

	if (!(*line = (char *)malloc(sizeof(char) * (loc + 1))))
	{
		free (*str);
		return (-1);
	}
	(*line)[loc] = '\0';
	*line = ft_strncpy(*line, *str, loc);
	if (!(temp = ft_strdup(*str + loc + 1)))
	{
		free (*str);
		free (*line);
		return (-1);
	}
	free(*str);
	*str = temp;
	return (1);
}

static int	ft_end_of_file(char **str, char **line, int size)
{
	int loc;

	if (size < 0)
	{
		if (*str)
			free (*str);
		return (-1);
	}
	else if (*str)
	{
		if ((loc = ft_find_newline(*str)) != -1)
			return (ft_split_linefid(str, line, loc));
		*line = *str;
		*str = NULL;
	}
	else
		if (!(*line = ft_strdup("")))
			return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX] = {0,};
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			loc;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!(str[fd] = ft_str_append(str[fd], buf, size)))
			return (-1);
		if ((loc = ft_find_newline(str[fd])) != -1)
			return (ft_split_linefid(&str[fd], line, loc));
	}
	return (ft_end_of_file(&str[fd], line, size));
}
