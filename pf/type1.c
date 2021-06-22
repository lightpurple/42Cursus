/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:57:14 by euhong            #+#    #+#             */
/*   Updated: 2021/06/22 22:12:44 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_id(va_list	*ap, t_info info)
{
	char	*num;
	int		len;

	if (!(num = ft_itoa(va_arg(*ap, int), info.prec)))
		return (0);
	if (info.prec >= info.width)
		len = print_zero(info.prec, ft_strlen(num), num);
	else if (info.minus != 0 && info.prec > ft_strlen(num))
	{
		len = print_zero(info.prec, ft_strlen(num), num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.minus != 0)
		len = print_space(info.width, ft_strlen(num), num, RIGHT);
	else if (info.zero != 0 && info.prec == -1)
		len = print_zero(info.width, ft_strlen(num), num);
	else if (info.prec > ft_strlen(num))
	{
		len = print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, ft_strlen(num), num);
	}
	else
		len = print_space(info.width, ft_strlen(num), num, LEFT);
	free (num);
	return (len);
}

int	print_c(va_list *ap, t_info info)
{
	unsigned char uc;

	uc = va_arg(*ap, int);
	if (info.width)
	{
		if (info.minus)
			return (print_space(info.width, 1, (char *)&uc, RIGHT));
		else
			return (print_space(info.width, 1, (char *)&uc, LEFT));
	}
	else
		write(1, &uc, 1);
	return (1);
}

int	print_s(va_list *ap, t_info info)
{
	char	*str;
	int		len;
	int		s_len;

	if (!(str = va_arg(*ap, char *)))
	{
		write(1, "(null)", 6);
		return (0);
	}
	len = 0;
	s_len = ft_strlen(str);
	if (info.width > s_len)
		len += print_space(info.width, s_len, 0, ONLY);
	if (info.prec < s_len)
	{
		while (info.prec-- > 0)
			len += write(1, str++, 1);
	}
	else
		len += write(1, str, s_len);
	return (len);
}

int	print_u(va_list *ap, t_info info)
{
	char	*num;
	int		len;

	if (!(num = ft_utoa(va_arg(*ap, unsigned int), info.prec)))
		return (0);
	if (info.prec >= info.width)
		len = print_zero(info.prec, ft_strlen(num), num);
	else if (info.minus != 0 && info.prec > ft_strlen(num))
	{
		len = print_zero(info.prec, ft_strlen(num), num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.minus != 0)
		len = print_space(info.width, ft_strlen(num), num, RIGHT);
	else if (info.zero != 0 && info.prec == -1)
		len = print_zero(info.width, ft_strlen(num), num);
	else if (info.prec > ft_strlen(num))
	{
		len = print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, ft_strlen(num), num);
	}
	else
		len = print_space(info.width, ft_strlen(num), num, LEFT);
	free (num);
	return (len);
}

int	print_p(va_list *ap, t_info info)
{
	unsigned long	p;
	int				i;
	int				len;
	char			str[15];

	i = 0;
	len = 0;
	p = (unsigned long)va_arg(*ap, uintptr_t *);
	setting_p(&str, p, info);
	if (info.minus)
		len += print_space(info.width, ft_strlen(str), str, RIGHT);
	else
		len += print_space(info.width, ft_strlen(str), str, LEFT);
	return (len);
}
