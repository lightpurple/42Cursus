/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:44 by euhong            #+#    #+#             */
/*   Updated: 2021/05/17 14:22:55 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_str_extend(char *str, char *buf, size_t  size)
{
	char	*line;
	char	*str_temp;
	int		i;
	int		len;

	i = 0;
	str_temp = str;
	len = ft_strlen(str);
	if (!(line = (char *)malloc(sizeof(char) * (len + size + 1))))
	{
		free(str);
		return (NULL);
	}
	while (*str)
		line[i++] = *str++;
	while (*buf)
		line[i++] = *buf++;
	line[i] = '\0';
	free(str_temp);
	return (line);
}

static int	ft_refresh(char **str)
{
	int		loc;
	int		len;
	char	*new;

	if ((loc = ft_find_newline(*str)) == -1)
		return (1);
	len = ft_strlen(*str);
	if (!(new = (char *)malloc(sizeof(char) * (len - loc))))
		return (0);
	new = ft_strncpy(new, &((*str)[loc + 1]), len - loc);
	free(*str);
	*str = new;
	return (1);
}

static char *ft_strdup(char **src, size_t loc)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (loc + 1))))
	{
		free(*src);
		return (NULL);
	}
	res = ft_strncpy(res, *src, loc);
	res[loc] = '\0';
	if (!(ft_refresh(src)))
	{
		free(*src);
		free(res);
		return (NULL);
	}
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			loc;
	int			size;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (!(str[fd] = ft_str_extend(str[fd], buf, size)))
			return (-1);
		if ((loc = ft_find_newline(str[fd])) != -1)
		{
			if (!(*line = ft_strdup(&str[fd], loc)))
				return (-1);
			return (1);
		}
	}
	if (size < 0)
	{
		free(str[fd]);
		return (-1);
	}
	return (0);
}
