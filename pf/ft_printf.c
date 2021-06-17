/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:56:35 by euhong            #+#    #+#             */
/*   Updated: 2021/06/17 15:25:13 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->prec_minus = 0;
	info->star[0] = 0;
	info->star[1] = 0;
	info->type = 0;
}

int		print_info(va_list ap, t_info info)
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
	if (info.type == 'n')
		len = print_n(ap, info);
	if (info.type == '%')
		len = write(1, "%", 1);
	return (len);
}

int		set_info(t_info *info, char c)
{
	if (c == '-' && info->prec == -1 && info->width == 0)
		info->minus = 1;
	else if (c == '-' && info->prec != -1)
	{
		info->minus = 1;
		info->prec_minus = 1;
	}
	else if (c == '0' && info->zero == 0)
		info->zero = 1;
	else if (c == '.')
		info->prec = 0;
	else if (c >= '0' && c <= '9' && info->prec != -1)
		info->prec = info->prec * 10 + c - '0';
	else if (c >= '0' && c <= '9')
		info->width = info->width * 10 + c - '0';
	else if (c == '*' && info->prec == -1 && info->star[0] != 1)
		info->star[0] = 1;
	else if (c == '*' && info->prec != -1 && info->star[1] != 1)
		info->star[1] = 1;
	else
		return (0);
	return (1);
}

int		treat_format(va_list ap, char *str)
{
	t_info	info;
	int		len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			init_info(&info);
			if (is_type(*++str))
				while (!set_info(&info, *str) && *str)
					str++;
			if (is_type(*str))
				return (len);
			info.type = *str;
			len += print_info(ap, info);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = treat_format(ap, (char *)str);
	va_end(ap);
	return (len);
}
