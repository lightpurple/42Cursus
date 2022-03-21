/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:29 by euhong            #+#    #+#             */
/*   Updated: 2022/03/21 17:32:26 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freest(t_llist **a, t_llist **b)
{
	t_llist *temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	while (*b)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
}

int			ft_atoi(char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
		if (sign == 1 && res > INTMAX)
			return (-1);
		else if (sign == -1 && res > INTMIN)
			return (0);
	}
	return ((int)res * sign);
}

void change(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int *arr, int start, int end)
{
	int i;
	int j;
	int temp;
	int key;

	if (start >= end)
		return;
	key = start;
	i = start+1;
	j = end;
	while (i <= j)
	{
		while(arr[i] <= arr[key] && i <= end)
			i++;
		while (arr[j] >= arr[key] && j > start)
			j--;
		if (i > j)
			change(&arr[key], &arr[j]);
		else
			change(&arr[i], &arr[j]);
	}
	quickSort(arr, start, j-1);
	quickSort(arr, j+1, end);
}

int cnt_list(t_llist *list)
{
	int idx;

	idx = 0;
	while (list)
	{
		idx++;
		list = list->next;
	}
	return (idx);
}
