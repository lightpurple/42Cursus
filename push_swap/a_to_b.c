/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:55:48 by euhong            #+#    #+#             */
/*   Updated: 2022/03/24 23:46:54 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_llist **a, t_llist **b, int cnt)
{
	int	op[3] = { 0, };
	int	pivot1;
	int pivot2;

	if (cnt <= 3 || cnt == 5)
	{
		sort(a, b, cnt, A);
		return ;
	}
	find_pivot(*a, cnt, &pivot1, &pivot2);
	while (cnt--)
	{
		if ((*a)->element < pivot2)
		{
			operator(b, a, &op[PB], P, B);
			if ((*b)->element >= pivot1 && (*b)->next)
				operator(b, NULL, &op[RB], R, B);
		}
		else
			operator(a, NULL, &op[RA], R, A);
	}
	rewind_stack(a, b, op[RA], op[RB]);
	a_to_b(a, b, op[RA]);
	b_to_a(a, b, op[RB]);
	b_to_a(a, b, op[PB] - op[RB]);
}

void b_to_a(t_llist **a, t_llist **b, int cnt)
{
	int	op[3] = { 0, };
	int	pivot1;
	int pivot2;

	if (cnt <= 3 || cnt == 5)
	{
		sort(a, b, cnt, B);
		return ;
	}
	find_pivot(*b, cnt, &pivot1, &pivot2);
	while (cnt--)
	{
		if ((*b)->element >= pivot1)
		{
			operator(a, b, NULL, P, A);
			if ((*a)->element < pivot2)
				operator(a, NULL, &op[RA], R, A);
		}
		else
			operator(b, NULL, &op[RB], R, B);
	}
	rewind_stack(a, b, op[RA], op[RB]);
	a_to_b(a, b, op[RA]);
	b_to_a(a, b, op[RB]);
}
