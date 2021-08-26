/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:14:50 by euhong            #+#    #+#             */
/*   Updated: 2021/08/26 16:55:41 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	my_handler(int signum)
{
	static unsigned char	num = 0;
	static int				i = 0;

	if (signum == SIGUSR1 && i != 8)
	{
		num |= (1 << i);
		i++;
	}
	else if (signum == SIGUSR2 && i != 8)
	{
		num |= (0 << i);
		i++;
	}
	if (i == 8)
	{
		if (num == 0)
			write(1, "\n", 1);
		else
			write(1, &num, 1);
		i = 0;
		num = 0;
	}
}

int	main(int arc, char **arv)
{
	int		pid;
	char	*str_pid;

	(void)arv;
	if (arc != 1)
	{
		put_str("The Server no need any argument!\n");
		exit(0);
	}
	pid = getpid();
	str_pid = ft_itoa(pid);
	if (str_pid == NULL)
		return (1);
	put_str("Server PID:");
	put_str(str_pid);
	put_str("\n");
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
