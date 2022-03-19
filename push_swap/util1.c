/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:29 by euhong            #+#    #+#             */
/*   Updated: 2022/03/19 21:40:06 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freest(t_llist **a, t_llist **b)
{
	t_llist *temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	while (*b)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
}

int			ft_atoi(char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
		if (sign == 1 && res > INTMAX)
			return (-1);
		else if (sign == -1 && res > INTMIN)
			return (0);
	}
	return ((int)res * sign);
}
