/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:55:48 by euhong            #+#    #+#             */
/*   Updated: 2022/03/28 23:14:23 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_op(int (*op)[3])
{
	(*op)[0] = 0;
	(*op)[1] = 0;
	(*op)[2] = 0;
}

void	a_to_b(t_llist **a, t_llist **b, int cnt)
{
	int	pivot[2];
	int	op[3];

	if (cnt <= 3 || cnt == 5)
		return (sort(a, b, cnt, A));
	set_op(&op);
	find_pivot(*a, cnt, &pivot[0], &pivot[1]);
	while (cnt--)
	{
		if ((*a)->element < pivot[1])
		{
			++op[PB];
			operator(b, a, P, B);
			if ((*b)->element >= pivot[0])
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
	int	pivot[2];
	int	op[3];

	if (cnt <= 3 || cnt == 5)
		return (sort(a, b, cnt, B));
	set_op(&op);
	find_pivot(*b, cnt, &pivot[0], &pivot[1]);
	while (cnt--)
	{
		if ((*b)->element >= pivot[0])
		{
			++op[PA];
			operator(a, b, P, A);
			if ((*a)->element < pivot[1])
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
