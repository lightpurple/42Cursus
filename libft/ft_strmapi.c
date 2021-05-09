/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:40:41 by euhong            #+#    #+#             */
/*   Updated: 2021/05/09 18:57:36 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	int			i;

	if (!s)
		return (NULL);
	if (!(res = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (res[++i])
		res[i] = f(i, res[i]);
	return (res);
}
