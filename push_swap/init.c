/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:10 by euhong            #+#    #+#             */
/*   Updated: 2022/03/23 16:31:42 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_llist(t_llist **list, int length)
{
	t_llist	*temp;

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
	i = 1;
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
	init_llist(b, 1);
	fill_llist(a, arv);
}
