/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:35:13 by euhong            #+#    #+#             */
/*   Updated: 2021/07/12 11:49:27 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	check_error(char *pid, char *str)
{
	while (*pid)
	{
		if (*pid < '0' || *pid > '9')
		{
			put_str("Pid consists only of numbers!\n");
			exit(0);
		}
		pid++;
	}
	if (!*str)
	{
		put_str("Please write a message!\n");
		exit(0);
	}
}

int		main(int arc, char **arv)
{
	int	pid;

	if (arc != 3)
	{
		put_str("Please follow the line\n./client [server-pid] [message]\n");
		exit(0);
	}
	check_error(arv[1], arv[2]);
	pid = ft_atoi(arv[1]);
	if (send_sig(pid, arv[2]))
		put_err("Signal Send Error\n");
	put_str("Message Sent Completed!");
	return (0);
}
