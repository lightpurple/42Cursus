/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:45:16 by euhong            #+#    #+#             */
/*   Updated: 2021/05/06 21:40:08 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_c(char c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int	sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_find_c(str[i], "\n\t\v\f\r "))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
		if (sign == 1 && res > 9223372036854775807)
			return (-1);
		else if (sign == -1 && res > 9223372036854775807)
			return (0);
	}
	return ((int)res * sign);
}
