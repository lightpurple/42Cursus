/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:20 by euhong            #+#    #+#             */
/*   Updated: 2022/03/19 21:37:21 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_llist **target)
{
	t_llist	*temp;

	if (!(*target) || !(*target)->next)
		return ;
	temp = (*target);
	temp->next = temp->next->next;
	(*target) = (*target)->next;
	(*target)->next = temp;
}

void push(t_llist **dst, t_llist **src)
{
	t_llist *temp;

	if ((*src) == NULL)
		return ;
	temp = (*src);
	temp->next = (*dst);
	(*dst) = temp;
	(*src) = (*src)->next;
}

void rotate(t_llist **target)
{
	t_llist *start;
	t_llist *end;

	if (!(*target) || !(*target)->next)
		return ;
	end = (*target);
	end->next = NULL;
	start = (*target)->next;
	while ((*target)->next)
		(*target) = (*target)->next;
	(*target)->next = end;
	(*target) = start;
}

void r_rotate(t_llist **target)
{
	t_llist *start;
	t_llist *second;

	if (!(*target) || !(*target)->next)
		return ;
	second = (*target);
	while ((*target)->next->next)
		(*target) = (*target)->next;
	start = (*target)->next;
	start->next = second;
	(*target)->next = NULL;
	(*target) = start;
}
