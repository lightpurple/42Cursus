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
// 			img = mlx_xpm_file_to_image(mlx, "->/image/tile->xpm", 0, 0);
// 			mlx_put_image_to_window(mlx, mlx_win, img, j * SIZE, i * SIZE);
// 		}
// 	}
// }

void mlx_start(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_press, 0);
	mlx_hook(data->mlx_win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	////////////
	int i = 0;
	int j;
	int *width;
	int *height;

	printf("%d %d", data->map->width, data->map->height);
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			data->img = mlx_xpm_file_to_image(
				data->mlx, "./image/young.xpm", width, height);
			mlx_put_image_to_window(
				data->mlx, data->mlx_win, data->img, j * SIZE, i * SIZE);
			// if (data->map->map[i][j] == '1')
			// {
			// 	data->img =
			// 		mlx_xpm_file_to_image(data->mlx, "./image/young.xpm", 0, 0);
			// 	mlx_put_image_to_window(
			// 		data->mlx, data->mlx_win, data->img, j * SIZE, i * SIZE);
			// }
			// else if (data->map->map[i][j] == '0')
			// {
			// 	data->img =
			// 		mlx_xpm_file_to_image(data->mlx, "./image/young.xpm", 0, 0);
			// 	mlx_put_image_to_window(
			// 		data->mlx, data->mlx_win, data->img, j * SIZE, i * SIZE);
			// }
			// else if (data->map->map[i][j] == 'P')
			// {
			// 	data->img = mlx_xpm_file_to_image(
			// 		data->mlx, "./image/mush/myoung.xpm", 0, 0);
			// 	mlx_put_image_to_window(
			// 		data->mlx, data->mlx_win, data->img, j * SIZE, i * SIZE);
			// }
			// else
			// {
			// 	data->img = mlx_xpm_file_to_image(
			// 		data->mlx, "./image/coin/cyoung.xpm", 0, 0);
			// 	mlx_put_image_to_window(
			// 		data->mlx, data->mlx_win, data->img, j * SIZE, i * SIZE);
			// }
			j++;
		}
		i++;
	}
	//////////////
	// mlx_loop_hook(mlx, stay_player, img->img);
	mlx_loop(data->mlx);
}
