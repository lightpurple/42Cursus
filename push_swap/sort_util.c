/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:51:43 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 23:11:12 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_operator(t_llist **target, int type, int stack)
{
	if (type == 0)
	{
		swap(target, stack);
		rotate(target, stack);
		swap(target, stack);
		r_rotate(target, stack);
	}
	else if (type == 1)
	{
		rotate(target, stack);
		swap(target, stack);
		r_rotate(target, stack);
	}
	else if (type == 2)
		swap(target, stack);
}

void	operator(t_llist **dst, t_llist **src, int op, int stack)
{
	if (op == P)
		push(dst, src, stack);
	else if (op == R)
		rotate(dst, stack);
	else if (op == RR)
		r_rotate(dst, stack);
	else if (op == RRR)
		r_rotate_both(dst, src, 1);
}

void	rewind_stack(t_llist **a, t_llist **b, int ra, int rb)
{
	while (ra && rb)
	{
		operator(a, b, RRR, 0);
		ra--;
		rb--;
	}
	while (ra--)
		operator(a, 0, RR, A);
	while (rb--)
		operator(b, 0, RR, B);
}

void	push_n(t_llist **dst, t_llist **src, int stack, int n)
{
	while (n--)
		push(dst, src, stack);
}

void	sort_2(t_llist **a, t_llist **b, int type)
{
	if (type == A)
		if ((*a)->element > (*a)->next->element)
			swap(a, A);
	if (type == B)
	{
		if ((*b)->element < (*b)->next->element)
			swap(b, B);
		push_n(a, b, A, 2);
	}
}
