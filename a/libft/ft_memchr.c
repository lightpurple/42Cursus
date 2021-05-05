/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:30:47 by euhong            #+#    #+#             */
/*   Updated: 2021/05/05 20:41:36 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	void	*result;
	size_t	i;

	result = (void *)s;
	i = -1;
	while (n--)
		if (((unsigned char *)result)[++i] == (unsigned char)c)
			return (&result[i]);
	return (NULL);
}
