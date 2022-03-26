/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:05 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 21:55:08 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cnt_str(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (cnt);
		while (*s != c && *s)
			s++;
		cnt++;
	}
	return (cnt);
}

static int	ft_make_free(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	return (1);
}

static char	*ft_strndup(char *s, int cnt)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (cnt + 1));
	i = -1;
	while (++i < cnt)
		temp[i] = s[i];
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c, int *arc)
{
	int		i;
	char	**str;
	char	*start;

	str = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	*arc = cnt_str(s, c) + 1;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = (char *)s;
		while (*s != c && *s)
			s++;
		str[i] = ft_strndup(start, s - start);
		if (!str[i])
			if (ft_make_free(str, i))
				break ;
		i++;
	}
	str[i] = 0;
	return (str);
}
