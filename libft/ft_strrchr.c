/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:35:00 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:14:23 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s[s_len] == (char)c)
		return (&((char *)s)[s_len]);
	while (s_len)
	{
		s_len--;
		if (s[s_len] == (char)c)
			return (&((char *)s)[s_len]);
	}
	return (0);
}
