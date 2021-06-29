/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 01:38:12 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:45:18 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setting_p(char **str, unsigned long p, t_info info)
{
	unsigned long	tmp;
	int				i;

	tmp = p;
	i = 3;
	while ((tmp /= 16) > 0)
		i++;
	(*str)[i--] = '\0';
	(*str)[0] = '0';
	(*str)[1] = 'x';
	(*str)[2] = '0';
	if (info.prec != -1 && p == 0)
	{
		(*str)[2] = '\0';
		return ;
	}
	while (p)
	{
		(*str)[i--] = hex_num(p % 16);
		p /= 16;
	}
}

int		print_space(int width, int s_len, char *num, int flag)
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

int		print_zero(int width, int s_len, char *num)
{
	int	len;

	len = 0;
	if (num[0] == '-')
		len += write(1, num++, 1);
	if (width > s_len)
		while (width-- > s_len)
			len += write(1, "0", 1);
	len += write(1, num, s_len);
	return (len);
}
