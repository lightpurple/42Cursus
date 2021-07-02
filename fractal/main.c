/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:06:54 by euhong            #+#    #+#             */
/*   Updated: 2021/07/02 18:16:26 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_list(void)
{
	printf("Available List!\n1. Julia\n2.  Mandelbrot\n");
	exit(TRUE);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (FALSE);
	while (*s1)
		if (*s1++ != *s2++)
			return (FALSE);
	return (TRUE);
}

int		verify_agv(char *agv)
{
	if (ft_strcmp(agv, "Julia") || ft_strcmp(agv, "Mandelbrot"))
		return (FALSE);
	return (TRUE);
}

int	main(int agc, char **agv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx_win = NULL;
	if (agc != 2 && verify_agv(agv[1]))
		print_list();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fractol");
	if (!mlx || !mlx_win)
		exit(FALSE);
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
