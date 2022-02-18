#include "ft.h"

void put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, SIZE * x, SIZE * y);
}

void draw_tile(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			put_img(game, game->floor.ptr, x, y);
			if (game->map.map[y][x] == '1')
				put_img(game, game->wall.ptr, x, y);
			x++;
		}
		y++;
	}
}

void draw_sprites(t_game *game, t_img **img)
{
	t_loc *tmp;

	tmp = game->collect.loc;
	while (tmp)
	{
		put_img(game, game->floor.ptr, tmp->x, tmp->y);
		put_img(game, (*img)->ptr, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	*img = (*img)->next;
}

void draw_portal(t_game *game)
{
	if (game->collect.loc)
		put_img(game, game->portal.ptr, game->portal.x, game->portal.y);
	else
		put_img(game, game->portal.next->ptr, game->portal.x, game->portal.y);
}
