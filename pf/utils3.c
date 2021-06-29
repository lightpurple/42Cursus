/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:29:36 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:45:13 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa(unsigned int num)
{
	int		i;
	char	*result;

	i = 0;
	i += cnt_hex(num);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (num == 0)
		result[0] = '0';
	result[i--] = '\0';
	while (num > 0)
	{
		result[i--] = hex_num(num % 16);
		num /= 16;
	}
	return (result);
}

char	*ft_itoa(int n)
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

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = cnt_unum(n);
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
int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*temp;
	int		len;

	len = ft_strlen(s1);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	if (len == 0)
		return (temp);
	while (--len)
		temp[len] = s1[len];
	temp[len] = s1[len];
	return (temp);
}
