/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:57:14 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:44:46 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reparse_id(int *s_len, t_info *info, char *num)
{
	if ((info->minus && info->zero) || info->prec >= 0 ||
		(info->prec < *s_len && info->width < *s_len))
		info->zero = 0;
	if (info->prec == 0 && num[0] == '0')
	{
		*s_len = 0;
		info->prec = 0;
	}
	if (num[0] == '-')
		info->prec = info->prec > --*s_len ? info->prec : *s_len;
	else
		info->prec = info->prec > *s_len ? info->prec : *s_len;
	if (info->prec < info->width)
	{
		if (num[0] == '-')
			info->width--;
		if (info->zero && info->width <= *s_len)
			info->prec = info->width;
	}
}

int		print_id(va_list *ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	if (!(num = ft_itoa(va_arg(*ap, int))))
		return (0);
	len = 0;
	s_len = ft_strlen(num);
	reparse_id(&s_len, &info, num);
	if (info.minus)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.zero)
		len += print_zero(info.width, info.prec, num);
	else
	{
		len += print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, s_len, num);
	}
	free(num);
	return (len);
}

int		print_u(va_list *ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	if (!(num = ft_utoa(va_arg(*ap, unsigned int))))
		return (0);
	len = 0;
	s_len = ft_strlen(num);
	reparse_id(&s_len, &info, num);
	if (info.minus)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.zero)
		len += print_zero(info.width, info.prec, num);
	else
	{
		len += print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, s_len, num);
	}
	free(num);
	return (len);
}

int		print_x(va_list *ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	if (!(num = ft_xtoa(va_arg(*ap, unsigned int))))
		return (0);
	len = 0;
	s_len = ft_strlen(num);
	reparse_id(&s_len, &info, num);
	if (info.minus)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.zero)
		len += print_zero(info.width, info.prec, num);
	else
	{
		len += print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, s_len, num);
	}
	free(num);
	return (len);
}

int		print_ux(va_list *ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	if (!(num = ft_xtoa(va_arg(*ap, unsigned int))))
		return (0);
	len = 0;
	change_up(&num);
	s_len = ft_strlen(num);
	reparse_id(&s_len, &info, num);
	if (info.minus)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.zero)
		len += print_zero(info.width, info.prec, num);
	else
	{
		len += print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, s_len, num);
	}
	free(num);
	return (len);
}
