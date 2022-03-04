/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:28 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 13:15:51 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	counting_star(int fd, t_game *game)
{
	int		i;
	int		res;
	char	temp;

	i = 0;
	res = 0;
	game->map.width = 0;
	while (read(fd, &temp, 1))
	{
		i++;
		if (temp == '\n')
		{
			if (game->map.width == 0)
				game->map.width = i - 1;
			res++;
		}
	}
	return (res);
}

void	map_parsing(char *file, t_game *game)
{
	int		i;
	int		fd;
	int		count;
	char	*str_tmp[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		wrong_exit();
	count = counting_star(fd, game);
	game->map.map = (char **)malloc(sizeof(char *) * (count + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	game->map.map[count] = 0;
	game->map.height = count;
	i = 0;
	while (i < count)
	{
		get_next_line(fd, str_tmp);
		game->map.map[i++] = ft_strdup(str_tmp[0]);
		free(*str_tmp);
	}
}
