/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:13 by euhong            #+#    #+#             */
/*   Updated: 2022/02/21 23:26:24 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		key_exit(t_game *game)
{
	printf("END\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int		loop_hook(t_game *game)
{
	draw_sprites(game, &(game->collect));
	draw_sprites(game, &(game->enermy));
	draw_sprites(game, game->player.stay);
	draw_portal(game);
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.map[game->player.y + y][game->player.x + x] == '1')
		return ;
	handle_player();
}

void	move_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		move_player(game, 0, 1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		move_player(game, 0, -1);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		move_player(game, 1, 0);
	}
}

int		key_hook(int keycode, t_game *game)
{
	if (game->move_status == NONE &&
		(keycode == KEY_A || key_exit == KEY_D || key_exit == KEY_S ||
			key_exit == KEY_W || key_exit == KEY_DOWN || key_exit == KEY_UP ||
			key_exit == KEY_LEFT || key_exit == KEY_RIGHT))
		move_key_hook(keycode, game);
	if (keycode == KEY_ESC)
		key_exit(game);
	return (1);
}

void	mlx_start(t_game *game)
{
	mlx_hook(game->mlx_win, KEY_EXIT, 0, &key_exit, &game);
	mlx_key_hook(game->mlx_win, &key_hook, &game);
	mlx_loop_hook(game->mlx, &loop_hook, &game);
	mlx_loop(game->mlx);
}
