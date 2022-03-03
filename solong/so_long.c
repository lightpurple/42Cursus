/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:57:12 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 01:11:39 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
