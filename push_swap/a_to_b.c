/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:55:48 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 22:04:16 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_llist **a, t_llist **b, int cnt)
{
	int	pivot1;
	int	pivot2;
	int	op[3] = {0, };

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
			++op[PB];
			operator(b, a, P, B);
			if ((*b)->element >= pivot1)
				if (++op[RB])
					operator(b, NULL, R, B);
		}
		else
			if (++op[RA])
				operator(a, NULL, R, A);
	}
	rewind_stack(a, b, op[RA], op[RB]);
	a_to_b(a, b, op[RA]);
	b_to_a(a, b, op[RB]);
	b_to_a(a, b, op[PB] - op[RB]);
}

void	b_to_a(t_llist **a, t_llist **b, int cnt)
{
	int	pivot1;
	int	pivot2;
	int	op[3] = {0, };

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
			++op[PA];
			operator(a, b, P, A);
			if ((*a)->element < pivot2)
				if (++op[RA])
					operator(a, NULL, R, A);
		}
		else
			if (++op[RB])
				operator(b, NULL, R, B);
	}
	a_to_b(a, b, op[PA] - op[RA]);
	rewind_stack(a, b, op[RA], op[RB]);
	a_to_b(a, b, op[RA]);
	b_to_a(a, b, op[RB]);
}
