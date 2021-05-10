/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:38:06 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:14:34 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		if (!(sub = (char *)malloc(sizeof(char))))
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (s_len - start + 1 < len)
		sub = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
