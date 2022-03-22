/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:54 by euhong            #+#    #+#             */
/*   Updated: 2022/03/22 16:57:40 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted(t_llist *a, int cnt)
{
	while (a->next && --cnt)
	{
		if (a->element > a->next->element)
			return (FAIL);
		a = a->next;
	}
	return (SUCCESS);
}

void sort_3(t_llist **list)
{
	int n1;
	int n2;
	int n3;

	n1 = (*list)->element;
	n2 = (*list)->next->element;
	n3 = (*list)->next->next->element;
	if (!check_sorted(*list, 3))
		return ;
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
	else
	{
		r_rotate(list, A);
		if (n1 < n3)
			swap(list, A);
	}
}

int find_pivot1(t_llist *list, int cnt)
{
	int i;
	int res;
	int *arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (cnt + 1));
	arr[cnt] = 0;
	while (i < cnt)
	{
		arr[i++] = list->element;
		list = list->next;
	}
	quickSort(arr, 0, cnt -1);
	res = arr[1];
	free(arr);
	return (res);
}

void sort_5(t_llist **a, t_llist **b)
{
	int pb;
	int pivot;

	if (!check_sorted(*a, 5))
		return ;
	pb = 0;
	pivot = find_pivot1(*a, 5);
	while (pb != 2)
	{
		if ((*a)->element <= pivot)
		{
			push(b, a, B);
			pb++;
		}
		else
			rotate(a, A);
	}
	sort_3(a);
	push(a, b, A);
	push(a, b, A);
	if ((*a)->element > (*a)->next->element)
		swap(a, A);
}

void simple_sort(t_llist **a, t_llist **b, int cnt)
{
	if (cnt == 3)
		sort_3(a);
	else
		sort_5(a, b);
}
