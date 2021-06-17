/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:55:43 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:10:04 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;

	if (!(temp = (char *)malloc(sizeof(char) * (count * size))))
		return (NULL);
	ft_bzero((void *)temp, (count * size));
	return (temp);
}
