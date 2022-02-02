/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:57:12 by euhong            #+#    #+#             */
/*   Updated: 2022/02/02 23:56:58 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void data_init(t_data **data)
{
	(*data)->mlx = mlx_init();
	(*data)->mlx_win = mlx_new_window((*data)->mlx,
									  (*data)->map->width * SIZE,
									  (*data)->map->height * SIZE,
									  "so_long");
}

int main(int arc, char **arv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	map_parsing(arv[1], &(data->map));
	data_init(&data);
	// error check
	mlx_start(data);
}
