/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:18 by euhong            #+#    #+#             */
/*   Updated: 2022/03/21 23:54:58 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_llist **a, t_llist **b)
{
	swap(a, A);
	swap(b, B);
}

void	rotate_both(t_llist **a, t_llist **b)
{
	rotate(a, A);
	rotate(b, B);
}

void	r_rotate_both(t_llist **a, t_llist **b)
{
	r_rotate(a, A);
	r_rotate(b, B);
}
