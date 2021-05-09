/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:49:33 by euhong            #+#    #+#             */
/*   Updated: 2021/05/06 22:26:49 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(s1);
	if(!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	if (len == 0)
		return (temp);
	while (--len)
		temp[len] = s1[len];
	temp[len] = s1[len];
	return (temp);
}
