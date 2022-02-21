/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:28 by euhong            #+#    #+#             */
/*   Updated: 2022/02/21 22:57:19 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		counting_star(int fd, t_game *game)
{
	int		size;
	int		res;
	int		i;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	res = 0;
	temp = NULL;
	game->map.width = 0;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
		temp = ft_str_append(temp, buf, size);
	while (temp[i] != EOF)
	{
		if (temp[i++] == '\n')
		{
			if (game->map.width == 0)
				game->map.width = i - 1;
			res++;
		}
	}
	free(temp);
	return (res);
}

void	map_parsing(char *file, t_game *game)
{
	int		i;
	int		fd;
	int		count;
	char	*str_tmp[1];

	fd = open(file, O_RDONLY);
	count = counting_star(fd, game);
	game->map.map = (char **)malloc(sizeof(char *) * (count + 1));
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
