/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:28:13 by euhong            #+#    #+#             */
/*   Updated: 2022/03/23 22:50:58 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operator(t_llist **dst, t_llist **src, int *cnt, int op, int stack)
{
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

void	sort_3(t_llist **a, t_llist **b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*list)->element;
	n2 = (*list)->next->element;
	n3 = (*list)->next->next->element;
	if (n1 > n2)
	{
		if (n1 > n3)
		{
			rotate(list, A);
			if (n2 > n3)
				swap(list, A);
		}
		else
			swap(list, A);
	}
	else if (n2 > n3)
	{
		r_rotate(list, A);
		if (n1 < n3)
			swap(list, A);
	}
}

void	rewind_stack(t_llist **a, t_llist **b, int ra, int rb)
{
	while (ra-- && rb--)
		operator(a, b, NULL, RRR, NULL);
	while (ra--)
		operator(a, NULL, NULL, RR, A);
	while (rb--)
		operator(b, NULL, NULL, RR, B);
}

void	a_to_b(t_llist **a, t_llist **b, int cnt)
{
	int	op[2] = { 0, };
	int	pivot1;
	int pivot2;

	if (cnt <= 3 || cnt == 5)
		sort(a, b, cnt); // 3이하에대해서 처리하는 sort만들기
	find_pivot(*a, cnt, &pivot1, &pivot2);
	while (cnt--)
	{
		if ((*a)->element >= pivot1)
		{
			operator(b, a, NULL, P, B);
			if ((*b)->element >= pivot2)
				operator(b, NULL, op[RB], R, B);
		}
		else
			operator(a, NULL, op[RA], R, A);
	}
	rewind_stack(a, b, op[RA], op[RB]);
}

void b_to_a(t_llist **a, t_llist **b, int cnt)
{
	int	op[2] = { 0, };
	int	pivot1;
	int pivot2;

	if (cnt == 3 || cnt == 5)
		sort(a, b, cnt);
	find_pivot(*b, cnt, &pivot1, &pivot2);
	while (cnt--)
	{
		if ((*b)->element <= pivot1)
		{
			operator(a, b, NULL, P, A);
			if ((*a)->element <= pivot2)
				operator(a, NULL, op[RA], R, A);
		}
		else
			operator(b, NULL, op[RB], R, B);
	}
	rewind_stack(a, b, op[RA], op[RB]);
}
