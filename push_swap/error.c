/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:06 by euhong            #+#    #+#             */
/*   Updated: 2022/03/19 21:37:07 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void no_arg(int arc)
{
	if (arc < 2)
	{
		print("There is no arguments\n", 2);
		exit(0);
	}
}

void not_int(char *arv[])
{
	int i;
	int j;

	i = 0;
	while (arv[++i])
	{
		j = -1;
		while (arv[i][++j])
		{
			if (j == 0 && arv[i][j] == '-' && (arv[i][j + 1] >= '1' && arv[i][j +1] <= '9'))
				continue;
			if (arv[i][0] == '0' || arv[i][j] < '0' || arv[i][j] > '9')
			{
				print("Some arguments aren't integers\n", 2);
				exit(0);
			}
		}
	}
}

void out_of_range(char *arv[])
{
	int i;
	int flag;

	i = 0;
	while (arv[++i])
	{
		flag = ft_atoi(arv[i]);
		if (flag == -1)
		{
			print("Some arguments are bigger than an integer\n", 2);
			exit(0);
		}
		else if (flag == 0)
		{
			print("Some arguments are smaller than an integer\n", 2);
			exit(0);
		}
	}
}

void same_arg(char *arv[])
{
	int i;
	int j;

	i = 0;
	while (arv[++i + 1])
	{
		j = i;
		while (arv[++j])
			if (ft_strcmp(arv[i], arv[j]))
			{
				print("There are duplicates\n", 2);
				exit(0);
			}
	}
}

void error_check(int arc, char *arv[])
{
	no_arg(arc);
	not_int(arv);
	out_of_range(arv);
	same_arg(arv);
}
