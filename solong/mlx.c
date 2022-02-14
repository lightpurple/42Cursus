#include "ft.h"

int key_press(int keycode)
{
	if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	return (0);
}

int key_exit(int keycode)
{
	if (keycode == X_EVENT_KEY_EXIT)
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


void draw_map(t_game *game, int x, int y)
{

	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.ptr, (40 * x), (40 * y));
	if (game->map.map[y][x] == 'E')
	{
		game->portal.x = x * 40;
		game->portal.y = y * 40;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->portal.ptr, game->portal.x, game->portal.y);
	}
	else if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.ptr, (40 * x), (40 * y));
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect.ptr, (40 * x), (40 * y));
}

void map_maker(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			draw_map(game, x, y);
			x++;
		}
		y++;
	}
}

void draw_unit(t_game *game)
{
	if (game)
		return;
}

void mlx_start(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 0, key_press, 0);
	mlx_hook(game->mlx_win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	////////////
	map_maker(game);
	draw_unit(game);
	//////////////
	// mlx_loop_hook(mlx, stay_player, img->img);
	mlx_loop(game->mlx);
}
