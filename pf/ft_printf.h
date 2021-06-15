/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:35:13 by euhong            #+#    #+#             */
/*   Updated: 2021/06/15 15:59:21 by euhong           ###   ########.fr       */
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
	int		zero;
	int		width;
	int		prec;
	int		sign;
	char	type;
}				t_info

#endif
