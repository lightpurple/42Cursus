#include "ft.h"

int key_press(int keycode)
{
	if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	return (0);
}

int key_exit(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	loop_hook(t_game *game)
{
	draw_sprites(game, &(game->collect.img));
	draw_sprites(game, &(game->enermy.img));
	draw_sprites(game, &(game->player.stay));
	draw_portal(game);
	return (1);
}

void mlx_start(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 0, key_press, 0);
	mlx_hook(game->mlx_win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	////////////
	mlx_loop_hook(game->mlx, &loop_hook, &game);
	mlx_loop(game->mlx);
}
