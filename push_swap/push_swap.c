/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:02 by euhong            #+#    #+#             */
/*   Updated: 2022/03/20 20:34:32 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arc, char *arv[])
{
	t_llist *a;
	t_llist *b;
	int	arr[arc];

	error_check(arc, arv);
	init(&a, &b, arc, arv);

	// sort

	freest(&a, &b);
	// 절반 나눠서 a는 오름차순, b는 내림차순으로 정렬
}
