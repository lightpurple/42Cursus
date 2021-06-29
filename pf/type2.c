/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:10:08 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:44:50 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_c(va_list *ap, t_info info)
{
	unsigned char	uc;

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

	len = 0;
	if (!(str = va_arg(*ap, char *)))
		if (!(str = ft_strdup("(null)")))
			return (len);
	s_len = ft_strlen(str);
	if (info.prec > 0)
		s_len = info.prec < s_len ? info.prec : s_len;
	else if (info.prec == 0)
		s_len = 0;
	if (info.minus)
		len += print_space(info.width, s_len, str, RIGHT);
	else
		len += print_space(info.width, s_len, str, LEFT);
	return (len);
}

int	print_p(va_list *ap, t_info info)
{
	unsigned long	p;
	int				len;
	char			*str;

	len = 0;
	p = (unsigned long)va_arg(*ap, uintptr_t *);
	if (!(str = (char *)malloc(sizeof(char) * 15)))
		return (len);
	setting_p(&str, p, info);
	if (info.minus)
		len += print_space(info.width, ft_strlen(str), str, RIGHT);
	else
		len += print_space(info.width, ft_strlen(str), str, LEFT);
	return (len);
}
