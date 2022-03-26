/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:45:16 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 23:34:56 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s2)
		return (0);
	return (1);
}

void	print(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

static int	ft_find_c(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	parse_arv(int *arc, char ***arv)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while ((*arv)[++i])
		if (ft_find_c((*arv)[i], ' '))
			cnt++;
	if (cnt == 0)
	{
		*arv = &arv[0][1];
		return ;
	}
	else if (i > 2)
	{
		print("This is not checker format!\n", 2);
		exit(0);
	}
	else
		*arv = ft_split((*arv)[1], ' ', arc);
}
