/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:57:14 by euhong            #+#    #+#             */
/*   Updated: 2021/06/28 22:08:13 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reparse_id(int s_len, t_info *info, char minus)
{
	if (info->prec < s_len)
		info->prec = s_len;
	if (minus)
		info->prec--;
	if (info->prec < 0)
		info->prec = 0;
}

int	print_id(va_list *ap, t_info info)
{
	char	*num;
	int		len;
	int		s_len;

	if (!(num = ft_itoa(va_arg(*ap, int), info.prec)))
		return (0);
	len = 0;
	s_len = ft_strlen(num);
	reparse_id(s_len, &info, num[0]);
	if (info.minus)
	{
		len += print_zero(info.prec, s_len, num);
		len += print_space(info.width, info.prec, num, ONLY);
	}
	else
	{
		len += print_space(info.width, info.prec, num, ONLY);
		len += print_zero(info.prec, s_len, num);
	}
	free(num);
	return (len);
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
