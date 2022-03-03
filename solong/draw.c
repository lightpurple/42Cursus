/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:00 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 01:11:51 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	draw_unit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] != '1')
				put_img(game, game->floor.ptr, x, y);
			if (game->map.map[y][x] == 'C')
				put_img(game, game->collect.ptr, x, y);
			if (game->map.map[y][x] == 'E')
				put_img(game, game->portal.ptr, x, y);
			x++;
		}
		y++;
	}
	put_img(game, game->player.ptr, game->player.x, game->player.y);
}

void	draw_tile(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			put_img(game, game->floor.ptr, x, y);
			if (game->map.map[y][x] == '1')
				put_img(game, game->wall.ptr, x, y);
			x++;
		}
		y++;
	}
}
