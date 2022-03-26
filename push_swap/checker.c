/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:25 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 23:44:27 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_llist **a, t_llist **b, char *op)
{
	if (ft_strcmp("pa", op))
		push(a, b, AB);
	else if (ft_strcmp("pb", op))
		push(b, a, AB);
	else if (ft_strcmp("sa", op))
		swap(a, AB);
	else if (ft_strcmp("sb", op))
		swap(b, AB);
	else if (ft_strcmp("ss", op))
		swap_both(a, b, 0);
	else if (ft_strcmp("ra", op))
		rotate(a, AB);
	else if (ft_strcmp("rb", op))
		rotate(b, AB);
	else if (ft_strcmp("rr", op))
		rotate_both(a, b, 0);
	else if (ft_strcmp("rra", op))
		r_rotate(a, AB);
	else if (ft_strcmp("rrb", op))
		r_rotate(b, AB);
	else if (ft_strcmp("rrr", op))
		r_rotate_both(a, b, 0);
}

void	checker(t_llist **a, t_llist **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_op(a, b, line);
		free(line);
	}
	free(line);
	if (!check_sorted(*a, cnt_list(*a)) && !*b)
		print("OK\n", 1);
	else
		print("KO\n", 1);
}

int	main(int arc, char *arv[])
{
	t_llist	*a;
	t_llist	*b;

	error_check(&arc, &arv);
	init(&a, &b, arc, arv);
	checker(&a, &b);
	freest(&a, &b);
	return (0);
}
