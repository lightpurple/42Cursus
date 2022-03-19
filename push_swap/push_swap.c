/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:02 by euhong            #+#    #+#             */
/*   Updated: 2022/03/19 21:37:03 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arc, char *arv[])
{
	t_llist *a;
	t_llist *b;

	error_check(arc, arv);
	init_llist(&a, arc - 1);
	init_llist(&b, 1);
	fill_llist(&a, arv);
	// sort
	freest(&a, &b);
	// 절반 나눠서 a는 오름차순, b는 내림차순으로 정렬
}
