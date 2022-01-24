/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:57:12 by euhong            #+#    #+#             */
/*   Updated: 2022/01/24 22:35:37 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int key_press(int keycode)
{
	if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	return (0);
}
// int		get_next_line(int fd, char **line);

int main(int arc, char **arv)
{
	void *mlx;
	void *mlx_win;
	t_map map;
	t_data img;
	int width = WIDTH;
	int height = HEIGHT;

	int fd = open(arv[1], O_RDONLY);
	printf("%s %d\n\n", arv[1], fd);
	get_next_line(fd, map.map);
	// for (int i = 0; map.map[i] == 0; i++)
	// {
	// 	printf("%s\n", map.map[i]);
	// }

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 300, "so_long");

	// img.img =
	// 	mlx_xpm_file_to_image(mlx, "./image/BullyMush.xpm", &width, &height);
	// mlx_hook(mlx_win, 2, 0, key_press, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 0);
	// mlx_loop(mlx);

	// error check
}
