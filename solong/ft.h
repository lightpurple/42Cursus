/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:19:23 by euhong            #+#    #+#             */
/*   Updated: 2022/02/18 23:20:41 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
#define FT_H

#include "./get_next_line.h"
#include "./minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 40

#define X_EVENT_KEY_EXIT 17

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define ERR_MSG "something wrong try again"
#endif

typedef struct s_map
{
	char **map;
	int width;
	int height;
} t_map;

typedef struct s_img
{
	int x;
	int y;
	void *ptr;
	struct s_img *next;
} t_img;

typedef struct s_loc
{
	int x;
	int y;
	struct s_loc *next;
} t_loc;

typedef struct s_sprite
{
	t_img *img;
	t_loc *loc;
} t_sprite;

typedef struct s_player
{
	int x;
	int y;
	t_img *stay;
	t_img *move;
} t_player;

typedef struct s_game
{
	void *mlx;
	void *mlx_win;
	int move;
	t_player player;
	t_img wall;
	t_img floor;
	t_img portal;
	t_sprite collect;
	t_sprite enermy;
	t_map map;
} t_game;

void map_parsing(char *file, t_game *game);
void mlx_start(t_game *game);
void game_init(t_game *game);
void init_map(t_game *game);
void put_img(t_game *game, void *img, int x, int y);
void draw_tile(t_game *game);
void draw_sprites(t_game *game, t_img **img);
void draw_portal(t_game *game);
void link_sprites(t_sprite *collect, int x, int y);

