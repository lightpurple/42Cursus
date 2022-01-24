/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:19:02 by euhong            #+#    #+#             */
/*   Updated: 2021/09/29 16:57:12 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	send_bit(int pid, char bit)
{
	if (bit)
	{
		if ((kill(pid, SIGUSR1)) == -1)
			return (1);
	}
	else if ((kill(pid, SIGUSR2)) == -1)
		return (1);
	return (0);
}

int	send_sig(int pid, char *str)
{
	int		i;
	char	bit;

	while (*str)
	{
		i = 0;
		while (i++ < 8)
		{
			bit = *str & 1;
			if (send_bit(pid, bit))
				return (1);
			*str >>= 1;
			usleep(200);
		}
		str++;
	}
	i = 0;
	while (++i <= 8)
	{
		if ((kill(pid, SIGUSR2)) == -1)
			return (1);
		usleep(200);
	}
	return (0);
}
