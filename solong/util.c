/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:37 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 13:15:13 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	wrong_exit(void)
{
	printf("%s", ERR_MSG);
	exit(0);
}

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
