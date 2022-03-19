/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:18 by euhong            #+#    #+#             */
/*   Updated: 2022/03/19 21:37:19 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_llist **a, t_llist **b)
{
	swap(a);
	swap(b);
}

void	rotate_both(t_llist **a, t_llist **b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate_both(t_llist **a, t_llist **b)
{
	r_rotate(a);
	r_rotate(b);
}
