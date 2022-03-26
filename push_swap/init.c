/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:10 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 21:53:01 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *flag)
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
			*flag = -1;
		else if (sign == -1 && res > INTMIN)
			*flag = 0;
	}
	return ((int)res * sign);
}

void	init_llist(t_llist **list, int length)
{
	t_llist	*temp;

	if (length == 0)
	{
		(*list) = NULL;
		return ;
	}
	(*list) = (t_llist *)malloc(sizeof(t_llist));
	temp = (*list);
	while (--length)
	{
		(*list)->next = (t_llist *)malloc(sizeof(t_llist));
		(*list) = (*list)->next;
	}
	(*list)->next = NULL;
	(*list) = temp;
}

void	fill_llist(t_llist **list, char *src[])
{
	int		i;
	t_llist	*temp;

	temp = (*list);
	i = 0;
	while (*list)
	{
		(*list)->element = ft_atoi((src[i++]), NULL);
		(*list) = (*list)->next;
	}
	(*list) = temp;
}

void	init(t_llist **a, t_llist **b, int arc, char *arv[])
{
	init_llist(a, arc - 1);
	init_llist(b, 0);
	fill_llist(a, arv);
}
