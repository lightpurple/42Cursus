/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:19:23 by euhong            #+#    #+#             */
/*   Updated: 2022/01/24 22:21:57 by euhong           ###   ########.fr       */
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

#define WIDTH 700
#define HEIGHT 500

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
} t_map;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;
