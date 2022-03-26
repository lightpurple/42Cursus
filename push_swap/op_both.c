/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:18 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 23:10:35 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_llist **a, t_llist **b, int flag)
{
	swap(a, AB);
	swap(b, AB);
	if (flag)
		print("ss\n", 1);
}

void	rotate_both(t_llist **a, t_llist **b, int flag)
{
	rotate(a, AB);
	rotate(b, AB);
	if (flag)
		print("rr\n", 1);
}

void	r_rotate_both(t_llist **a, t_llist **b, int flag)
{
	r_rotate(a, AB);
	r_rotate(b, AB);
	if (flag)
		print("rrr\n", 1);
}
