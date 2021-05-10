/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:05 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:13:13 by euhong           ###   ########.fr       */
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
	while (--i > 0)
		free(str[i]);
	free(str);
}

static int	ft_find_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
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
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = cnt_str(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (*s == c)
			s++;
		if (!(str[i] = ft_strndup((char *)s, ft_find_c((char *)s, c))))
		{
			ft_make_free(str, i);
			return (NULL);
		}
		while (*s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}
