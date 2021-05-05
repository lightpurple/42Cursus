/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:55:43 by euhong            #+#    #+#             */
/*   Updated: 2021/05/05 23:12:45 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	cnt;

	cnt = size * count;
	temp = (char *)malloc(cnt);
	if (!temp)
		return (NULL);
	while (cnt)
		temp[cnt--] = 0;
	temp[0] = 0;
	return ((void *)temp);
}
