/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:51:43 by euhong            #+#    #+#             */
/*   Updated: 2022/03/24 21:12:19 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operator(t_llist **dst, t_llist **src, int *cnt, int op, int stack)
{
	if (cnt)
		(*cnt)++;
	if (op == P)
		push(dst, src, stack);
	else if (op == R)
		rotate(dst, stack);
	else if (op == RR)
		r_rotate(dst, stack);
	else if (op == RRR)
		r_rotate_both(dst, src);
}

void	rewind_stack(t_llist **a, t_llist **b, int ra, int rb)
{
	while (ra && rb)
	{
		operator(a, b, 0, RRR, 0);
		ra--;
		rb--;
	}
	while (ra--)
		operator(a, 0, 0, RR, A);
	while (rb--)
		operator(b, 0, 0, RR, B);
}

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
