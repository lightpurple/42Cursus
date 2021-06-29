/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:52 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:44:56 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_int(t_info *info)
{
	info->minus = 1;
	info->width *= -1;
}

int		treat_star(va_list *ap, t_info *info)
{
	if ((info->star[0] && info->width) || (info->prec > 0 && info->star[1]))
		return (1);
	if (info->star[0] && info->star[1])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			reverse_int(info);
		info->prec = va_arg(*ap, int);
	}
	else if (info->star[0])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			reverse_int(info);
	}
	else if (info->star[1])
		info->prec = va_arg(*ap, int);
	return (0);
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->star[0] = 0;
	info->star[1] = 0;
	info->type = 0;
}

int		print_info(va_list *ap, t_info info)
{
	int	len;

	if (info.type == 'i' || info.type == 'd')
		len = print_id(ap, info);
	if (info.type == 'c')
		len = print_c(ap, info);
	if (info.type == 's')
		len = print_s(ap, info);
	if (info.type == 'u')
		len = print_u(ap, info);
	if (info.type == 'p')
		len = print_p(ap, info);
	if (info.type == 'x')
		len = print_x(ap, info);
	if (info.type == 'X')
		len = print_ux(ap, info);
	if (info.type == '%')
		len = print_perc(info);
	return (len);
}
