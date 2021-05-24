/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:25:17 by euhong            #+#    #+#             */
/*   Updated: 2021/05/20 09:12:23 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	return (dst);
}

int		ft_find_newline(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_strncat(char *dst, char *src, int len)
{
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	while (j < len)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*temp;
	int		len;

	len = ft_strlen(s1);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	if (len == 0)
		return (temp);
	while (--len)
		temp[len] = s1[len];
	temp[len] = s1[len];
	return (temp);
}
