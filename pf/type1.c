/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:57:14 by euhong            #+#    #+#             */
/*   Updated: 2021/06/18 15:19:56 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_id(va_list	ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	len = 0;
	if (!(num = ft_itoa(va_arg(ap, int))) || info.prec == 0)
		return (0);
	s_len = ft_strlen(num);
	if (info.prec_minus != 0)
		len += print_space(info.prec, s_len, num, LEFT);
	else if (info.minus != 0 && info.prec >= info.width)
		len += print_zero(info.prec, s_len, num);
	else if (info.minus != 0)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else if (info.zero != 0 && info.prec == -1)
		len += print_zero(info.width, s_len, num);
	else if (info.width > info.prec)
		len += print_space(info.width, s_len, num, LEFT);
	else if (info.width <= info.prec)
		len += print_zero(info.width, s_len, num);
	return (len);
}

int	print_c(va_list ap, t_info info)
{
	unsigned char uc;

	uc = va_arg(ap, unsigned char);
	if (info.width)
	{
		if (info.minus)
			return (print_space(info.width, 1, &uc, LEFT));
		else
			return (print_space(info.width, 1, &uc, RIGHT));
	}
	else
		write(1, &uc, 1);
	return (1);
}

int	print_s(va_list ap, t_info info)
{
	char	*str;

	str = va_arg(ap, char *);
	return (write(1, str, ft_strlen(str)));
}

int	print_u(va_list ap, t_info info)
{

}

int	print_p(va_list ap, t_info info)
{

}
