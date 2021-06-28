/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:10:08 by euhong            #+#    #+#             */
/*   Updated: 2021/06/28 22:03:19 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(int width, int s_len, char *num, int flag)
{
	int	len;

	len = 0;
	if (flag == ONLY)
	{
		while (width-- > s_len)
			len += write(1, " ", 1);
	}
	else if (flag == LEFT)
	{
		if (width > s_len)
			while (width-- > s_len)
				len += write(1, " ", 1);
		len += write(1, num, s_len);
	}
	else
	{
		len += write(1, num, s_len);
		if (width > s_len)
			while (width-- > s_len)
				len += write(1, " ", 1);
	}
	return (len);
}

int	print_zero(int width, int s_len, char *num)
{
	int	len;

	len = 0;
	if (width > s_len)
		while (width-- > s_len)
			len += write(1, "0", 1);
	len += write(1, num, s_len);
	return (len);
}

int	print_x(va_list *ap, t_info info)
{
	char	*num;
	int		len;

	if (!(num = ft_xtoa(va_arg(*ap, unsigned int), info.prec)))
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
		len = print_zero(info.width - 1, ft_strlen(num), num);
	else if (info.prec > ft_strlen(num))
	{
		len = print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, ft_strlen(num), num);
	}
	else
		len = print_space(info.width, ft_strlen(num), num, LEFT);
	free(num);
	return (len);
}

int	print_ux(va_list *ap, t_info info)
{
	char	*num;
	int		len;

	if (!(num = ft_xtoa(va_arg(*ap, unsigned int), info.prec)))
		return (0);
	change_up(&num);
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
		len = print_zero(info.width - 1, ft_strlen(num), num);
	else if (info.prec > ft_strlen(num))
	{
		len = print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, ft_strlen(num), num);
	}
	else
		len = print_space(info.width, ft_strlen(num), num, LEFT);
	free(num);
	return (len);
}

int	print_perc(t_info info)
{
	if (info.width > 0)
	{
		if (info.minus)
			return (print_space(info.width, 1, "%", RIGHT));
		else if (info.zero)
			return (print_zero(info.width, 1, "%"));
		else
			return (print_space(info.width, 1, "%", LEFT));
	}
	else
		return (write(1, "%", 1));
}
