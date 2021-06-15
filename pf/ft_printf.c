/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:56:35 by euhong            #+#    #+#             */
/*   Updated: 2021/06/15 16:10:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_info(t_info	*info)
{
	info->sign = 0;
	info->minus = 0;
	info->zero = 0;
	info->prec = -1;
	info->width = 0;
	info->type = 0;
}

int		print_info(va_list	ap, t_info	info)
{
	int	len;

	if (info->type == 'i' || info->type == 'd')
		len = printid(va_arg(ap, int), info);
	if (info->type == 'c')
		len = printc(va_arg(ap, char), info);
	if (info->type == 's')
		len = prints(va_arg(ap, char *), info);
	if (info->type == 'u')
		len = printu(va_arg(ap, unsigned int), info);
	if (info->type == 'p')
		len = printp(va_arg(ap, void *), info);
	if (info->type == 'x')
		len = printx(va_arg(ap, int), info);
	if (info->type == 'X')
		len = printux(va_arg(ap, int), info);
	if (info->type == 'n')
		len = printn(&(va_arg(ap, int *)), info);
	if (info->type == '%')
		len = write(1, "%", 1);
	return (len);
}

int		set_info(t_info	*info, char **str)
{
	if (c == '0' && info->width == 0 && info->prec == -1)
	{
		info->zero = 1;
		*str++;
	}
	while (**str >= '0' && **str <= '9')
	{
		info->width = info->width * 10 + (**str - '0');
		*str++;
	}
	if (**str == '.')
	{
		*str++;
		info->prec = 0;
		while (**str >= '0' && **str <= '9')
		{
			info->prec = info->prec * 10 + (**str - '0');
			*str++;
		}
	}
	if (is_type(**str))
		return (1);
	info->type = **str;
	return (0)
}

int		find_type(va_list ap, char **str)
{
	t_info	info;
	int		len;

	init_info(&info);
	*str++;
	if (is_type(**str))
		if (set_info(&info, str))
			return (0);
	info.type = *str;
	len = print_info(ap, info);
	return (len);
}

int		treat_format(va_list ap, char *str)
{
	int 	len;

	len = 0;
	while (*str)
	{
		if (*str == %)
			len += find_type(ap, &str);
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
