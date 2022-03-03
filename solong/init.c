/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:07 by euhong            #+#    #+#             */
/*   Updated: 2022/03/03 16:34:52 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_img	new_img(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	init_images(t_game *game)
{
	game->wall = new_img(game->mlx, "./image/wall.xpm");
	game->floor = new_img(game->mlx, "./image/floor.xpm");
	game->portal = new_img(game->mlx, "./image/portal.xpm");
	game->player = new_img(game->mlx, "./image/mush.xpm");
	game->collect = new_img(game->mlx, "./image/coin.xpm");
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
		game->mlx, game->map.width * SIZE, game->map.height * SIZE, "so_long");
}

void	init_map(t_game *game)
{
	draw_tile(game);
	draw_unit(game);
}

void	game_init(t_game *game)
{
	init_mlx(game);
	init_images(game);
	init_map(game);
}
