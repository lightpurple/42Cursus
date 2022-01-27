#include "ft.h"

int counting_star(int fd, t_map *map)
{
	int size;
	int res;
	int i;
	char *temp;
	char buf[BUFFER_SIZE + 1];

	i = 0;
	res = 0;
	temp = NULL;
	map->width = 0;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
		temp = ft_str_append(temp, buf, size);
	while (temp[i] != EOF)
	{
		if (temp[i++] == '\n')
		{
			if (map->width == 0)
				map->width = i;
			res++;
		}
	}
	free(temp);
	return res;
}

void map_parsing(char *file, t_map *map)
{
	int fd;
	int count;
	int i;
	char *str_tmp[1];

	fd = open(file, O_RDONLY);
	count = counting_star(fd, map);
	(*map).map = (char **)malloc(sizeof(char *) * (count + 1));
	fd = open(file, O_RDONLY);
	(*map).map[count] = 0;
	(*map).height = count;
	i = 0;
	while (i < count)
	{
		get_next_line(fd, str_tmp);
		(*map).map[i++] = ft_strdup(str_tmp[0]);
	}
	free(*str_tmp);
}
