/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:56:35 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:44:36 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_info(t_info *info, char c)
{
	if (c == '-' && info->prec == -1 && info->width == 0)
		info->minus = 1;
	else if (c == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (c == '.' && info->prec == -1)
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

int	treat_format(va_list *ap, char *str)
{
	t_info	info;
	int		len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			init_info(&info);
			str++;
			while (set_info(&info, *str) && *str)
				str++;
			if (is_type(*str))
				return (len);
			info.type = *str;
			if (info.star[0] || info.star[1])
				if (treat_star(ap, &info))
					return (len);
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
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = treat_format(&ap, (char *)str);
	va_end(ap);
	return (len);
}
