/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:52 by euhong            #+#    #+#             */
/*   Updated: 2021/06/23 01:59:48 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int		treat_star(va_list *ap, t_info *info)
{
	if ((info->star[0] || info->star[1]) && (info->prec || info->width))
		return (1);
	if (info->star[0] && info->star[1])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			return (1);
		if ((info->prec = va_arg(*ap, int)) < 0)
			return (1);
	}
	else if (info->star[0])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			return (1);
	}
	else if (info->star[1])
	{
		if ((info->prec = va_arg(*ap, int)) < 0)
			info->prec = -1;
	}
	return (0);
}

char	*ft_xtoa(int num)
{
	int		i;
	int		tmp;
	char	*result;

	i = 0;
	tmp = num;
	while (tmp > 0)
	{
		tmp /= 16;
		i++;
	}
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	result[i--] = '\0';
	while (num > 0)
	{
		result[i--] = hex_num(num % 16);
		num /= 16;
	}
	return (result);
}

char	hex_num(int num)
{
	if (num >= 10)
		num += 87;
	else
		num += 48;
	return (num);
}

void	change_up(char **num)
{
	int	i;

	i = ft_strlen(*num);
	while (i-- >= 0)
		if ((*num)[i] >= 'a' && (*num)[i] <= 'z')
			(*num)[i] -= 32;
}
