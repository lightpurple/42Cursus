/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:44 by euhong            #+#    #+#             */
/*   Updated: 2021/05/17 19:53:21 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_append(char *str, int s_len, char *buf, int b_len)
{
	char	*res;

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

int	ft_split_linefid(char **str, char **line, int loc)
{
	char	*temp;

	*line = ft_strncpy(*line, *str, loc);
	if (!(temp = ft_strdup(&((*str)[loc]))))
		return (-1);
	free(*str);
	*str = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			str_len;
	int			loc;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	str_len = 0;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!(str[fd] = ft_str_append(&(*str)[fd], str_len, buf, size)))
			return (-1);
		str_len += size;
		if ((loc = ft_find_newline(buf)) != -1)
			return (ft_split_linefid(&str[fd], line, loc));
	}
	return (0);
}
