/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:18 by euhong            #+#    #+#             */
/*   Updated: 2022/03/22 00:05:54 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_llist **a, t_llist **b)
{
	swap(a, AB);
	swap(b, AB);
	print("ss\n", 1);
}

void	rotate_both(t_llist **a, t_llist **b)
{
	rotate(a, AB);
	rotate(b, AB);
	print("rr\n", 1);
}

void	r_rotate_both(t_llist **a, t_llist **b)
{
	r_rotate(a, AB);
	r_rotate(b, AB);
	print("rrr\n", 1);
}
