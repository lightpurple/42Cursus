/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:13 by euhong            #+#    #+#             */
/*   Updated: 2022/03/03 17:03:45 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		key_exit(t_game *game)
{
	printf("END\n");
	(void)game;
	exit(0);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.map[game->player.y + y][game->player.x + x] == '1')
		return ;
	game->movement++;
	print_movement(game->movement);
	if (!game->collect_cnt &&
		game->map.map[game->player.y + y][game->player.x + x] == 'E')
		key_exit(game);
	if (game->map.map[game->player.y][game->player.x] != 'E')
		game->map.map[game->player.y][game->player.x] = '0';
	game->player.x += x;
	game->player.y += y;
	draw_unit(game);
} // C로 움직일경우 segmentation fault
// 나머지 bus error

void	move_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_W)
		move_player(game, 0, 1);
	else if (keycode == KEY_S)
		move_player(game, 0, -1);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
}

int		key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S ||
		keycode == KEY_W)
		move_key_hook(keycode, game);
	if (keycode == KEY_ESC)
		key_exit(game);
	return (1);
}

void	mlx_start(t_game *game)
{
	mlx_key_hook(game->mlx_win, key_hook, &game);
	mlx_hook(game->mlx_win, KEY_EXIT, 0, key_exit, &game);
	mlx_loop(game->mlx);
}
