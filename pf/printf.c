/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:56:35 by euhong            #+#    #+#             */
/*   Updated: 2021/06/14 22:21:20 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_info(t_info	*info)
{
	info->sign = 0;
	info->zero = 0;
	info->prec = -1;
	info->width = 0;
	info->type = 0;
}

int		print_info(va_list	ap, t_info	info)
{

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
	int		cnt;

	len = 0;
	while (*str)
	{
		if (*str == %)
		{
			cnt = find_type(ap, &str);
			len += cnt;
		}
		else
		{
			write(1, str, 1);
			len++;
		}
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
