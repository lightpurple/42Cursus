/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:14:50 by euhong            #+#    #+#             */
/*   Updated: 2021/07/06 22:15:05 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	int a = getpid();
	char *kk = ft_itoa(a);
	int len = ft_strlen(kk);
	write(1, kk, len);
}
