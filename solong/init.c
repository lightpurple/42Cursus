#include "ft.h"

t_img new_img(void *mlx, char *path)
{
	t_img img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return img;
}

void init_sprites(void *mlx, t_img **sprite,  char *path, int count)
{
	int num;
	int idx;
	char *file;
	t_img *tmp;

	num = -1;
	*sprite = (t_img *)malloc(sizeof(t_img));
	tmp = *sprite;
	while (++num < count)
	{
		idx = num + '0';
		file = ft_str_append(path, (char *)&idx, 1);
		file = ft_str_append(file, ".xpm", 4);
		tmp->ptr = mlx_xpm_file_to_image(mlx, file, &tmp->x, &tmp->y);
		if (count - 1 != num)
		{
			tmp->next = (t_img *)malloc(sizeof(t_img));
			tmp = tmp->next;
		}
	}
	tmp->next = *sprite;
}

void init_images(t_game *game)
{
	game->wall = new_img(game->mlx, "./image/wall.xpm");
	game->floor = new_img(game->mlx, "./image/floor.xpm");
	game->portal = new_img(game->mlx, "./image/portal.xpm");
	init_sprites(game->mlx, &(game->player.stay), "./image/mush/mush", 3);
	init_sprites(game->mlx, &(game->player.move), "./image/mush_move/mush_move", 4);
	init_sprites(game->mlx, &(game->collect.img), "./image/coin/coin", 8);
}

void init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
		game->mlx, game->map.width * SIZE, game->map.height * SIZE, "so_long");
}

void init_game(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				link_sprites(&game->collect, x, y);
			else if (game->map.map[y][x] == 'F')
				link_sprites(&game->enermy, x, y);
			x++;
		}
		y++;
	}
}

void init_map(t_game *game)
{
	draw_tile(game);
	draw_sprites(game, &(game->collect.img));
	// draw_sprites(game, &(game->enermy.img));
	draw_portal(game);
}

void game_init(t_game *game)
{
	init_mlx(game);
	init_game(game);
	init_images(game);
	init_map(game);
}
