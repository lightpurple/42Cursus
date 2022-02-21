/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:07 by euhong            #+#    #+#             */
/*   Updated: 2022/02/21 23:20:13 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_img	new_img(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	init_sprites(void *mlx, t_img **img, char *path, int count)
{
	int		num;
	int		idx;
	char	*file;
	t_img	*tmp;

	num = -1;
	*img = (t_img *)malloc(sizeof(t_img));
	tmp = *img;
	while (++num < count)
	{
		idx = num + '0';
		file = ft_str_append(path, (char *)&idx, 1);
		file = ft_str_append(file, ".xpm", 4);
		tmp->ptr = mlx_xpm_file_to_image(mlx, file, &tmp->x, &tmp->y);
		if (count - 1 != num)
		{
			tmp->next = (t_img *)malloc(sizeof(t_img));
			tmp = tmp->next;
		}
	}
	tmp->next = *img;
}

void	init_images(t_game *game)
{
	game->wall = new_img(game->mlx, "./image/wall.xpm");
	game->floor = new_img(game->mlx, "./image/floor.xpm");
	game->portal = new_img(game->mlx, "./image/portal.xpm");
	init_sprites(game->mlx, &(game->player.stay->img), "./image/mush/mush", 3);
	init_sprites(
		game->mlx, &(game->player.move->img), "./image/mush_move/mush_move", 4);
	init_sprites(game->mlx, &(game->collect.img), "./image/coin/coin", 8);
	// init_sprites(game->mlx, &(game->enermy.img), "./image/enermy/enermy", 8);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
		game->mlx, game->map.width * SIZE, game->map.height * SIZE, "so_long");
}

void	setting_player(t_game *game)
{
	game->player.move->loc->x = game->player.x;
	game->player.move->loc->y = game->player.y;
	game->player.move->loc->next = NULL;
	game->player.stay->loc->x = game->player.x;
	game->player.stay->loc->y = game->player.y;
	game->player.stay->loc->next = NULL;
}

void	init_game(t_game *game)
{
	int	x;
	int	y;

	setting_player(game);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				link_sprites(&game->collect, x, y);
			else if (game->map.map[y][x] == 'F')
				link_sprites(&game->enermy, x, y);
			x++;
		}
		y++;
	}
}

void	init_map(t_game *game)
{
	draw_tile(game);
	draw_sprites(game, &(game->collect));
	// draw_sprites(game, &(game->enermy));
	draw_portal(game);
}

void	game_init(t_game *game)
{
	init_mlx(game);
	init_game(game);
	init_images(game);
	init_map(game);
}
