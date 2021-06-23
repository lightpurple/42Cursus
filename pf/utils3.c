/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:29:36 by euhong            #+#    #+#             */
/*   Updated: 2021/06/23 15:29:59 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setting_p(char (*str)[15], unsigned long p, t_info info)
{
	unsigned long	tmp;
	int				i;

	tmp = p;
	i = 3;
	while ((tmp /= 16) > 0)
		i++;
	(*str)[i--] = '\0';
	(*str)[0] = '0';
	(*str)[1] = 'x';
	if (info.prec != -1)
	{
		(*str)[2] = '\0';
		return ;
	}
	(*str)[2] = '0';
	while (p)
	{
		(*str)[i--] = hex_num(p % 16);
		p /= 16;
	}
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}
