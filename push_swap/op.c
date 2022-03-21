/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:20 by euhong            #+#    #+#             */
/*   Updated: 2022/03/21 21:19:30 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_llist **target, int stack)
{
	char *op;
	t_llist	*temp;

	if (!(*target) || !(*target)->next)
		return ;
	temp = (*target);
	temp->next = temp->next->next;
	(*target) = (*target)->next;
	(*target)->next = temp;
	op = stack == A ? "SA\n" : "SB\n";
	print(op, 1);
}

void push(t_llist **dst, t_llist **src, int stack)
{
	char *op;
	t_llist *temp;

	if ((*src) == NULL)
		return ;
	temp = (*src);
	temp->next = (*dst);
	(*dst) = temp;
	(*src) = (*src)->next;
	op = stack == A ? "PA\n" : "PB\n";
	print(op, 1);
}

void rotate(t_llist **target, int stack)
{
	char *op;
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
	op = stack == A ? "RA\n" : "RB\n";
	print(op, 1);
}

void r_rotate(t_llist **target, int stack)
{
	char *op;
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
	op = stack == A ? "RRA\n" : "RRB\n";
	print(op, 1);
}
