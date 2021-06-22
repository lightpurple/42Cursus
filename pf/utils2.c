/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:51:17 by euhong            #+#    #+#             */
/*   Updated: 2021/06/22 22:14:21 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	cnt_num(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static int	cnt_unum(unsigned int n)
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

char		*ft_itoa(int	n, int	out)
{
	char	*num;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = out == 0 ? 0 : cnt_num(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	if (n == 0 && out != 0)
		num[len] = '0';
	while (n != 0)
	{
		num[len--] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		num[0] = '-';
	return (num);
}

char		*ft_utoa(unsigned int	n, int out)
{
	char	*num;
	int		len;

	len = out == 0 ? 0 : cnt_unum(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	if (n == 0 && out != 0)
		num[len] = '0';
	while (n != 0)
	{
		num[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
