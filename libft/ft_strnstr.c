/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:59:42 by euhong            #+#    #+#             */
/*   Updated: 2021/05/06 21:14:53 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_c(char *src, char *find)
{
	while (*find)
	{
		if (*src != *find)
			return (0);
		src++;
		find++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!needle && !haystack)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (ft_strlen(haystack) < needle_len || needle_len > len)
		return (NULL);
	i = -1;
	while (++i + needle_len <= len)
		if (ft_find_c(&((char *)haystack)[i], (char *)needle))
			return (&((char *)haystack)[i]);
	return (NULL);
}
