/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:05 by euhong            #+#    #+#             */
/*   Updated: 2021/05/08 14:38:50 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_str(char const *s, char c)
{
	int cnt;
	int i;

	cnt = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (i == 0)
				continue;
			else
				cnt++;
		}
		else
			if (s[i + 1] == '\0')
				cnt++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1))))
		return (NULL);
	i = 0;
	while ()
}
