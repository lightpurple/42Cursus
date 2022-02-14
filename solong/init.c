#include "ft.h"

t_img new_sprite(void *mlx, char *path)
{
	t_img img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return img;
}

void init_images(t_game *game)
{
	game->collect = new_sprite(game->mlx, "./image/coin/coin0.xpm");
	game->wall = new_sprite(game->mlx, "./image/wall.xpm");
	game->floor = new_sprite(game->mlx, "./image/floor.xpm");
	game->portal = new_sprite(game->mlx, "./image/portal.xpm");
	game->player.stay_loop0 = new_sprite(game->mlx, "./image/mush/mush0.xpm");
	game->player.stay_loop1 = new_sprite(game->mlx, "./image/mush/mush1.xpm");
	game->player.stay_loop2 = new_sprite(game->mlx, "./image/mush/mush2.xpm");
	game->player.move_loop0 = new_sprite(game->mlx, "./image/mush_move/mosh_move0.xpm");
	game->player.move_loop1 = new_sprite(game->mlx, "./image/mush_move/mosh_move1.xpm");
	game->player.move_loop2 = new_sprite(game->mlx, "./image/mush_move/mosh_move2.xpm");
	game->player.move_loop3 = new_sprite(game->mlx, "./image/mush_move/mosh_move3.xpm");
}

void game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
		game->mlx, (game->map.width - 1) * SIZE, game->map.height * SIZE, "so_long");
	init_images(game);
}
