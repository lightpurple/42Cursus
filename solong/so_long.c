/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:57:12 by euhong            #+#    #+#             */
/*   Updated: 2022/03/03 16:25:30 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	err_chk(t_map map, int arc)
{
	int	x;
	int	y;

	if (arc != 2)
		return (1);
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
			x++;
		if (x != map.width)
			return (1);
		y++;
	}
	if (y != map.height)
		return (1);
	return (0);
}

int	main(int arc, char **arv)
{
	t_game	game;

	map_parsing(arv[1], &game);
	game_init(&game);
	if (err_chk(game.map, arc))
	{
		printf("%s", ERR_MSG);
		exit(0);
	}
	mlx_start(&game);
}
