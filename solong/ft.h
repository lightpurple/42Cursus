/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:19:23 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 13:30:17 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "./get_next_line.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define FAIL 1

# define SIZE 40

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define ERR_MSG "something wrong try again"

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_img
{
	int				x;
	int				y;
	void			*ptr;
	struct s_img	*next;
}					t_img;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	int				movement;
	int				collect_cnt;
	t_img			player;
	t_img			wall;
	t_img			floor;
	t_img			portal;
	t_img			collect;
	t_map			map;
}					t_game;

void				map_parsing(char *file, t_game *game);
void				mlx_start(t_game *game);
void				game_init(t_game *game);
void				init_map(t_game *game);
void				put_img(t_game *game, void *img, int x, int y);
void				draw_tile(t_game *game);
void				draw_unit(t_game *game);
void				print_movement(int movement);
void				put_img(t_game *game, void *img, int x, int y);
int					err_chk(t_map map, int arc);
t_img				new_img(void *mlx, char *path);
void				wrong_exit(void);

#endif
