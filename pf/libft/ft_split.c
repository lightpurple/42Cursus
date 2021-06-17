/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:05 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 20:10:05 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_make_free(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
}

static char	*ft_strndup(char *s, int cnt)
{
	char	*temp;
	int		i;

	if (!(temp = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	i = -1;
	while (++i < cnt)
		temp[i] = s[i];
	temp[i] = '\0';
	return (temp);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	char	*start;
	int		i;

	if (!s || !(str = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1))))
		return (NULL);
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
		if (!(str[i] = ft_strndup(start, s - start)))
		{
			ft_make_free(str, i);
			break ;
		}
		i++;
	}
	str[i] = 0;
	return (str);
}
