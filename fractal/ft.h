/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:27:58 by euhong            #+#    #+#             */
/*   Updated: 2021/07/02 17:24:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define WIDTH 1920
# define HEIGHT 1080
# define TRUE 0
# define FALSE 1

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


#endif
