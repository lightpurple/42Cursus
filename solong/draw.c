/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:00 by euhong            #+#    #+#             */
/*   Updated: 2022/02/21 23:19:02 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, SIZE * x, SIZE * y);
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

void	draw_sprites(t_game *game, t_sprite *sprite)
{
	t_loc	*tmp;

	tmp = (*sprite)->loc;
	while (tmp)
	{
		put_img(game, game->floor.ptr, tmp->x, tmp->y);
		put_img(game, (*sprite)->img->ptr, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	(*sprite)->img = (*sprite)->img->next;
}

void	draw_portal(t_game *game)
{
	if (game->collect.loc)
		put_img(game, game->portal.ptr, game->portal.x, game->portal.y);
	else
		put_img(game, game->portal.next->ptr, game->portal.x, game->portal.y);
}
