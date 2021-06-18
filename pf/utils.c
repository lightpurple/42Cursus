/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:52 by euhong            #+#    #+#             */
/*   Updated: 2021/06/18 13:50:42 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
	c == 'x' || c == 'X' || c == '%' || c == 'n')
		return (0);
	return (1);
}

int			treat_star(va_list ap, t_info *info)
{
	if ((info->star[0] || info->star[1]) && (info->prec || info->width))
		return (1);
	if (info->star[0] && info->star[1])
	{
		if ((info->width = va_arg(ap, int)) < 0)
			return (1);
		if ((info->prec = va_arg(ap, int)) < 0)
			return (1);
	}
	else if (info->star[0])
	{
		if ((info->width = va_arg(ap, int)) < 0)
			return (1);
	}
	else if (info->star[1])
	{
		if ((info->prec = va_arg(ap, int)) < 0)
			return (1);
	}
	return (0);
}
