/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:28:13 by euhong            #+#    #+#             */
/*   Updated: 2022/03/24 22:36:35 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_3_b(t_llist **target)
{
	int num[3];

	num[0] = (*target)->element;
	num[1] = (*target)->next->element;
	num[2] = (*target)->next->next->element;
	if (num[0] < num[1] && num[0] < num[2])
	{
		sort_3_operator(target, 0, B);
		if (num[1] < num[2])
			sort_3_operator(target, 2, B);
	}
	else if (num[1] < num[0] && num[1] < num[2])
	{
		sort_3_operator(target, 1, B);
		if (num[0] < num[2])
			sort_3_operator(target, 2, B);
	}
	else if (num[0] < num[1])
		sort_3_operator(target, 2, B);
}

void	sort_3_a(t_llist **target)
{
	int num[3];

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
	int pa;
	int rb;
	int pivot;

	pa = 0;
	rb = 0;
	find_pivot(*b, 5, NULL, &pivot);
	while (pa != 2)
	{
		if ((*b)->element >= pivot)
		{
			push(a, b, A);
			pa++;
		}
		else
			if (++rb)
				rotate(b, B);
	}
	while (rb--)
		r_rotate(b, B);
	sort_3_b(b);
	while (pa--)
		push(b, a, B);
	if ((*b)->element < (*b)->next->element)
		swap(b, B);
}

void	sort_5_a(t_llist **a, t_llist **b)
{
	int pb;
	int ra;
	int pivot;

	pb = 0;
	ra = 0;
	find_pivot(*a, 5, &pivot, NULL);
	while (pb != 2)
	{
		if ((*a)->element <= pivot)
		{
			push(b, a, B);
			pb++;
		}
		else
			if (++ra)
				rotate(a, A);
	}
	while (ra--)
		r_rotate(a, A);
	sort_3_a(a);
	while (pb--)
		push(a, b, A);
	if ((*a)->element > (*a)->next->element)
		swap(a, A);
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
	{
		sort_3_b(b);
		push_n(a, b, A, cnt);
	}
	else if (cnt == 5 && type == A)
		sort_5_a(a, b);
	else if (cnt == 5 && type == B)
	{
		sort_5_b(a, b);
		push_n(a, b, A, cnt);
	}
}
