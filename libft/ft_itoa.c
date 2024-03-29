/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:50:03 by euhong            #+#    #+#             */
/*   Updated: 2021/05/10 11:10:51 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = cnt_num(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	if (n == 0)
	{
		num[len] = '0';
		return (num);
	}
	while (n != 0)
	{
		num[len--] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		num[0] = '-';
	return (num);
}
