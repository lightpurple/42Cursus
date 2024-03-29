/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:02 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 21:36:49 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_llist **a, t_llist **b)
{
	int	cnt;

	cnt = cnt_list(*a);
	if (!check_sorted(*a, cnt))
		return ;
	if (cnt == 3 || cnt == 5)
		simple_sort(a, b, cnt);
	else
		a_to_b(a, b, cnt);
}

int	main(int arc, char *arv[])
{
	t_llist	*a;
	t_llist	*b;

	error_check(&arc, &arv);
	init(&a, &b, arc, arv);
	push_swap(&a, &b);
	freest(&a, &b);
}
