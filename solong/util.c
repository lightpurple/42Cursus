/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:37 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 01:43:26 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, SIZE * x, SIZE * y);
}

t_img	new_img(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	img.next = NULL;
	return (img);
}

void	print_movement(int movement)
{
	printf("movement => %d\n", movement);
}

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
