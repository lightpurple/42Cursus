#include "ft.h"

int key_press(int keycode)
{
	if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	return (0);
}

int key_exit(int keycode)
{
	exit(0);
	return (0);
}

// int stay_player(void *img, void *mlx, void *mlx_win)
// {
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		if (i == 3)
// 			i = 0;
// 		else
// 		{
// 			img = mlx_xpm_file_to_image(mlx, "./image/tile.xpm", 0, 0);
// 			// mlx_put_image_to_window(mlx, mlx_win, img, j * SIZE, i * SIZE);
// 		}
// 	}
// }

void mlx_start(t_map map)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int *width;
	int *height;

	*width = 50;
	*height = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map.width * SIZE, map.height * SIZE, "so_long");

	mlx_hook(mlx_win, 2, 0, key_press, 0);
	mlx_hook(mlx_win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	////////////
	int i = 0;
	int j;

	printf("%d %d", map.width, map.height);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j] == '1')
			{
				img.img = mlx_xpm_file_to_image(
					mlx, "./image/wall.xpm", width, height);
				mlx_put_image_to_window(
					mlx, mlx_win, img.img, j * SIZE, i * SIZE);
			}
			else if (map.map[i][j] == '0')
			{
				img.img = mlx_xpm_file_to_image(
					mlx, "./image/tile.xpm", width, height);
				mlx_put_image_to_window(
					mlx, mlx_win, img.img, j * SIZE, i * SIZE);
			}
			else if (map.map[i][j] == 'P')
			{
				img.img = mlx_xpm_file_to_image(
					mlx, "./image/mush/mush0.xpm", width, height);
				mlx_put_image_to_window(
					mlx, mlx_win, img.img, j * SIZE, i * SIZE);
			}
			else
			{
				img.img = mlx_xpm_file_to_image(
					mlx, "./image/coin/coin0.xpm", width, height);
				mlx_put_image_to_window(
					mlx, mlx_win, img.img, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
	//////////////
	// mlx_loop_hook(mlx, stay_player, img.img);
	mlx_loop(mlx);
}
