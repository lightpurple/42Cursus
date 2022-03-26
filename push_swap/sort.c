/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:28:13 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 21:47:05 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_b(t_llist **a, t_llist **b)
{
	int	num[3];

	num[0] = (*b)->element;
	num[1] = (*b)->next->element;
	num[2] = (*b)->next->next->element;
	if (num[0] < num[1] && num[0] < num[2])
	{
		sort_3_operator(b, 0, B);
		if (num[1] < num[2])
			sort_3_operator(b, 2, B);
	}
	else if (num[1] < num[0] && num[1] < num[2])
	{
		sort_3_operator(b, 1, B);
		if (num[0] < num[2])
			sort_3_operator(b, 2, B);
	}
	else if (num[0] < num[1])
		sort_3_operator(b, 2, B);
	push_n(a, b, A, 3);
}

void	sort_3_a(t_llist **target)
{
	int	num[3];

	num[0] = (*target)->element;
	num[1] = (*target)->next->element;
	num[2] = (*target)->next->next->element;
	if (num[0] > num[1] && num[0] > num[2])
	{
		sort_3_operator(target, 0, A);
		if (num[1] > num[2])
			sort_3_operator(target, 2, A);
	}
	else if (num[1] > num[0] && num[1] > num[2])
	{
		sort_3_operator(target, 1, A);
		if (num[0] > num[2])
			sort_3_operator(target, 2, A);
	}
	else if (num[0] > num[1])
		sort_3_operator(target, 2, A);
}

void	sort_5_b(t_llist **a, t_llist **b)
{
	int	pa;
	int	rb;
	int	pivot;

	pa = 0;
	rb = 0;
	find_pivot(*b, 5, NULL, &pivot);
	while (pa != 2)
	{
		if ((*b)->element >= pivot)
		{
			if (++pa)
				operator(a, b, P, A);
		}
		else
			if (++rb)
				operator(b, NULL, R, B);
	}
	sort_2(a, NULL, A);
	while (rb--)
		r_rotate(b, B);
	sort_3_b(a, b);
}

void	sort_5_a(t_llist **a, t_llist **b)
{
	int	pb;
	int	ra;
	int	pivot;

	pb = 0;
	ra = 0;
	find_pivot(*a, 5, &pivot, NULL);
	while (pb != 2)
	{
		if ((*a)->element <= pivot)
		{
			if (++pb)
				operator(b, a, P, B);
		}
		else
			if (++ra)
				operator(a, NULL, R, A);
	}
	while (ra--)
		r_rotate(a, A);
	sort_3_a(a);
	push_n(a, b, A, 2);
	sort_2(a, NULL, A);
}

void	sort(t_llist **a, t_llist **b, int cnt, int type)
{
	if (cnt == 1 && type == B)
		push(a, b, A);
	else if (cnt == 2 && type == A)
		sort_2(a, b, A);
	else if (cnt == 2 && type == B)
		sort_2(a, b, B);
	else if (cnt == 3 && type == A)
		sort_3_a(a);
	else if (cnt == 3 && type == B)
		sort_3_b(a, b);
	else if (cnt == 5 && type == A)
		sort_5_a(a, b);
	else if (cnt == 5 && type == B)
		sort_5_b(a, b);
}
