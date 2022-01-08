/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:41 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:42 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_data	*init_fr(t_data *fr)
{	
	reset_fractol(fr);
	fr->mlx = mlx_init();
	fr->mlx_win = mlx_new_window(fr->mlx, W, H, fr->title);
	fr->img = mlx_new_image(fr->mlx, W, H);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel, &fr->line_length,
			&fr->endian);
	return (fr);
}

int	main(int argc, char **argv)
{
	t_data	img;

	img.title = ft_strjoin("Fract`ol - ", argv[1]);
	if (ft_strequ(argv[1], "mandelbrot"))
	{
		img.fractol = 1;
		init_fr(&img);
		mandelbrot(&img);
	}
	else if (ft_strequ(argv[1], "julia"))
	{	
		img.fractol = 2;
		init_fr(&img);
		julia(&img);
	}
	else
	{
		printf("Choose Fractol - Mandelbrot or Julia");
		return (0);
	}
	mlx_hook(img.mlx_win, 2, 5, key_handler, &img);
	mlx_hook(img.mlx_win, 4, (1L << 2), mouse_mandelbrot, &img);
	if (img.fractol == 2)
		mlx_hook(img.mlx_win, 6, (1L << 6), mouse_julia, &img);
	mlx_loop(img.mlx);
}
