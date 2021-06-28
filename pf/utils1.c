/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:52 by euhong            #+#    #+#             */
/*   Updated: 2021/06/28 16:05:33 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_int(t_info *info)
{
	info->minus = 1;
	info->width *= -1;
}

int		treat_star(va_list *ap, t_info *info)
{
	if ((info->star[0] && info->width) || (info->prec > 0 && info->star[1]))
		return (1);
	if (info->star[0] && info->star[1])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			reverse_int(info);
		info->prec = va_arg(*ap, int);
	}
	else if (info->star[0])
	{
		if ((info->width = va_arg(*ap, int)) < 0)
			reverse_int(info);
	}
	else if (info->star[1])
		info->prec = va_arg(*ap, int);
	return (0);
}

int		cnt_hex(unsigned int num)
{
	int i;

	i = 0;
	if (!num)
		return (1);
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	hex_num(int num)
{
	if (num >= 10)
		num += 87;
	else
		num += 48;
	return (num);
}

char	*ft_xtoa(unsigned int num, int out)
{
	int				i;
	unsigned int	tmp;
	char			*result;

	i = (num != 0) ? 0 : 1;
	tmp = num;
	i += cnt_hex(num);
	i = out != 0 ? i : 0;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (tmp == 0 && out != 0)
		result[0] = '0';
	result[i--] = '\0';
	while (tmp > 0)
	{
		result[i--] = hex_num(tmp % 16);
		tmp /= 16;
	}
	return (result);
}

void	change_up(char **num)
{
	int	i;

	i = ft_strlen(*num);
	while (i-- >= 0)
		if ((*num)[i] >= 'a' && (*num)[i] <= 'z')
			(*num)[i] -= 32;
}
