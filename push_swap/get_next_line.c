/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:44 by euhong            #+#    #+#             */
/*   Updated: 2022/03/27 22:26:15 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_append(char *str, char *buf, int b_len)
{
	char	*res;
	int		s_len;

	s_len = 0;
	if (str)
		s_len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (s_len + b_len + 1));
	*res = '\0';
	if (str)
		res = ft_strncat(res, str, s_len);
	res = ft_strncat(res, buf, b_len);
	if (str)
		free(str);
	return (res);
}

int	ft_split_linefid(char **str, char **line, int loc)
{
	char	*temp;

	*line = (char *)malloc(sizeof(char) * (loc + 1));
	(*line)[loc] = '\0';
	*line = ft_strncpy(*line, *str, loc);
	temp = ft_strdup(*str + loc + 1);
	free(*str);
	*str = temp;
	return (1);
}

int	ft_end_of_file(char **str, char **line, int size)
{
	int	loc;

	if (size < 0)
	{
		if (*str)
			free(*str);
		return (-1);
	}
	else if (*str)
	{
		loc = ft_find_newline(*str);
		if (loc != -1)
			return (ft_split_linefid(str, line, loc));
		*line = *str;
		*str = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			loc;
	static char	*str[OPEN_MAX] = {0,	};

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		str[fd] = ft_str_append(str[fd], buf, size);
		if (!str[fd])
			return (-1);
		loc = ft_find_newline(str[fd]);
		if (loc != -1)
			return (ft_split_linefid(&str[fd], line, loc));
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_end_of_file(&str[fd], line, size));
}
