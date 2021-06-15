/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:35:13 by euhong            #+#    #+#             */
/*   Updated: 2021/06/15 22:01:10 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int			is_type(char c);

typedef	struct	s_info
{
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		width;
	int		prec;
	char	star[2];
	char	type;
}				t_info

#endif
