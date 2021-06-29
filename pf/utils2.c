/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:51:17 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:45:03 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cnt_hex(unsigned int num)
{
	int	i;

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

int		cnt_num(int n)
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

int		cnt_unum(unsigned int n)
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

char	hex_num(int num)
{
	if (num >= 10)
		num += 87;
	else
		num += 48;
	return (num);
}

void	change_up(char **num)
{
	int	i;

	i = ft_strlen(*num);
	while (i-- >= 0)
		if ((*num)[i] >= 'a' && (*num)[i] <= 'z')
			(*num)[i] -= 32;
}
