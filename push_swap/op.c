/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:20 by euhong            #+#    #+#             */
/*   Updated: 2022/03/23 00:17:55 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_llist **target, int stack)
{
	char	*op;
	t_llist	*temp;

	if (!(*target) || !(*target)->next)
		return ;
	temp = (*target);
	(*target) = (*target)->next;
	temp->next = temp->next->next;
	(*target)->next = temp;
	if (stack != AB)
	{
		if (stack == A)
			op = "sa\n";
		else
			op = "sb\n";
		print(op, 1);
	}
}

void	push(t_llist **dst, t_llist **src, int stack)
{
	char	*op;
	t_llist	*temp;

	if ((*src) == NULL)
		return ;
	temp = (*src);
	(*src) = (*src)->next;
	temp->next = (*dst);
	(*dst) = temp;
	if (stack == A)
		op = "pa\n";
	else
		op = "pb\n";
	print(op, 1);
}

void	rotate(t_llist **target, int stack)
{
	char	*op;
	t_llist	*start;
	t_llist	*end;

	if (!(*target) || !(*target)->next)
		return ;
	end = (*target);
	start = (*target)->next;
	while ((*target)->next)
		(*target) = (*target)->next;
	end->next = NULL;
	(*target)->next = end;
	(*target) = start;
	if (stack != AB)
	{
		if (stack == A)
			op = "ra\n";
		else
			op = "rb\n";
		print(op, 1);
	}
}

void	r_rotate(t_llist **target, int stack)
{
	char	*op;
	t_llist	*start;
	t_llist	*second;

	if (!(*target) || !(*target)->next)
		return ;
	second = (*target);
	while ((*target)->next->next)
		(*target) = (*target)->next;
	start = (*target)->next;
	start->next = second;
	(*target)->next = NULL;
	(*target) = start;
	if (stack != AB)
	{
		if (stack == A)
			op = "rra\n";
		else
			op = "rrb\n";
		print(op, 1);
	}
}
