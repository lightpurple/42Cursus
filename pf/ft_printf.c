/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:56:35 by euhong            #+#    #+#             */
/*   Updated: 2021/06/15 22:01:05 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_info(t_info	*info)
{
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->sharp = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->star[0]= 0;
	info->star[1]= 0;
	info->type = 0;
}

int		print_info(va_list	ap, t_info	info)
{
	int	len;

	if (info->type == 'i' || info->type == 'd')
		len = printid(ap, info);
	if (info->type == 'c')
		len = printc(ap, info);
	if (info->type == 's')
		len = prints(ap, info);
	if (info->type == 'u')
		len = printu(ap, info);
	if (info->type == 'p')
		len = printp(ap, info);
	if (info->type == 'x')
		len = printx(ap, info);
	if (info->type == 'X')
		len = printux(ap, info);
	if (info->type == 'n')
		len = printn(&(ap, info);
	if (info->type == '%')
		len = write(1, "%", 1);
	return (len);
}

int		set_info(t_info	*info, char c)
{
	if (c == '-' && info->prec == -1)
		info->minus = 1;
	else if (c == '+')
		info->plus = 1;
	else if (c == ' ' && c != '+')
		info->space = 1;
	else if (c == '#')
		info->sharp = 1;
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
	int 	len;

	len = 0;
	while (*str)
	{
		if (*str == %)
		{
			init_info(&info);
			if (is_type(*++str))
				while (!set_info(*str) && *str)
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

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		len;

	va_start(ap, str);
	len = treat_format(ap, (char *)str);
	va_end(ap);
}
