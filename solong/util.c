/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:37 by euhong            #+#    #+#             */
/*   Updated: 2022/02/20 15:37:39 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	link_sprites(t_sprite *collect, int x, int y)
{
	collect->loc->x = x;
	collect->loc->y = y;
	collect->loc->next = (t_loc *)malloc(sizeof(t_loc));
	collect->loc = collect->loc->next;
	collect->loc->next = NULL;
}
