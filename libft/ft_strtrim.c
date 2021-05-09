/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:46:44 by euhong            #+#    #+#             */
/*   Updated: 2021/05/09 18:38:33 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_c(char c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_find_c(s1[start], (char *)set))
		start++;
	while (end && ft_find_c(s1[end], (char *)set))
		end--;
	if (start > end)
	{
		if (!(res = (char *)malloc(sizeof(char))))
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	ft_strlcpy(res, &s1[start], (end - start + 2));
	return (res);
}
