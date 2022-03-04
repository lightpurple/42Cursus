/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:36:57 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 13:24:12 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_tile(t_map map)
{
	int		x;
	int		y;
	char	cur;

	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			cur = map.map[y][x];
			if (((y == 0 || y == map.height - 1) && cur != '1') || \
			((x == 0 || x == map.width - 1) && cur != '1'))
				return (FAIL);
			if (cur != '0' && cur != '1' && cur != 'E' && cur != 'P' && \
			cur != 'C')
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	check_one(t_map map)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (map.map[y][x] == 'P')
				player++;
			if (map.map[y][x] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1)
		return (FAIL);
	return (SUCCESS);
}

int	err_chk(t_map map, int arc)
{
	if (check_tile(map) || check_one(map) || arc != 2)
		return (FAIL);
	return (SUCCESS);
}
