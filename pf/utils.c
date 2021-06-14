/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:52 by euhong            #+#    #+#             */
/*   Updated: 2021/06/14 22:11:56 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	cnt_num(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = cnt_num(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	if (n == 0)
		num[len] = '0';
	while (n != 0)
	{
		num[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

int			is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
	c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}
