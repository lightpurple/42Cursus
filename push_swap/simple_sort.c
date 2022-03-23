/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:54 by euhong            #+#    #+#             */
/*   Updated: 2022/03/23 17:50:04 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_llist *a, int cnt)
{
	while (a->next && --cnt)
	{
		if (a->element > a->next->element)
			return (FAIL);
		a = a->next;
	}
	return (SUCCESS);
}

void	simple_sort_3(t_llist **list)
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

void	simple_sort_5(t_llist **a, t_llist **b)
{
	int	pb;
	int	pivot;

	if (!check_sorted(*a, 5))
		return ;
	pb = 0;
	find_pivot(*a, 5, &pivot, NULL);
	while (pb != 2)
	{
		if ((*a)->element < pivot)
		{
			push(b, a, B);
			pb++;
		}
		else
			rotate(a, A);
	}
	simple_sort_3(a);
	push(a, b, A);
	push(a, b, A);
	if ((*a)->element > (*a)->next->element)
		swap(a, A);
}

void	simple_sort(t_llist **a, t_llist **b, int cnt)
{
	if (cnt == 3)
		simple_sort_3(a);
	else
		simple_sort_5(a, b);
}
