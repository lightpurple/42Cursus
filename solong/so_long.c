/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:57:12 by euhong            #+#    #+#             */
/*   Updated: 2022/02/03 00:16:06 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void data_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
		game->mlx, game->map.width * SIZE, game->map.height * SIZE, "so_long");
}

int main(int arc, char **arv)
{
	t_game game;

	map_parsing(arv[1], &game);
	game_init(&game);
	// error check
	mlx_start(&game);
}
