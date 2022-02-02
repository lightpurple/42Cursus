/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:19:23 by euhong            #+#    #+#             */
/*   Updated: 2022/02/02 23:56:55 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
#define FT_H

#include "./gnl/get_next_line.h"
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
#endif

typedef struct s_loc
{
	int x;
	int y;
} t_loc;

typedef struct s_map
{
	char **map;
	int width;
	int height;
} t_map;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	void *img;
	t_map *map;
	t_loc *loc;
} t_data;

void map_parsing(char *file, t_map **map);
void mlx_start(t_data *data);
