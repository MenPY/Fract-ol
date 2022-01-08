/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:38 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:39 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

double	my_pow(t_data *mlx)
{
	double	result;

	result = pow(mlx->z.re, 2.0) + pow(mlx->z.re, 2.0);
	return (result);
}

void	init_prop(t_data *mlx)
{
	mlx->prop.re = (mlx->max.re - mlx->min.re) / W;
	mlx->prop.im = (mlx->max.im - mlx->min.im) / H;
	mlx->y = -1;
}

void	mandelbrot(t_data *mlx)
{
	init_prop(mlx);
	while (++mlx->y < H)
	{
		mlx->x = -1;
		while (++mlx->x < W)
		{
			mlx->c = complex(mlx->min.re + mlx->x * (mlx->prop.re),
					mlx->max.im - mlx->y * (mlx->prop.im));
			mlx->z = complex(mlx->c.re, mlx->c.im);
			mlx->iter = -1;
			while ((my_pow(mlx) <= 30) && ++mlx->iter < MAX_ITER)
			{
				mlx->z = complex(pow(mlx->z.re, 2.0) - pow(mlx->z.im, 2.0)
						+ mlx->c.re, 2.0 * mlx->z.re * mlx->z.im + mlx->c.im);
				if ((mlx->z.re * mlx->z.re) + (mlx->z.im * mlx->z.im) > 4.0)
				{
					pxl(mlx, mlx->x, mlx->y, color(mlx->iter, mlx->z, mlx));
					break ;
				}
				else
					pxl(mlx, mlx->x, mlx->y, 0x000000);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	julia(t_data *mlx)
{
	init_prop(mlx);
	while (++mlx->y < H)
	{
		mlx->x = -1;
		while (++mlx->x < W)
		{
			mlx->c = complex(mlx->min.re + mlx->x * (mlx->prop.re),
					mlx->max.im - mlx->y * (mlx->prop.im));
			mlx->z = complex(mlx->c.re, mlx->c.im);
			mlx->iter = -1;
			while ((my_pow(mlx) <= 50) && ++mlx->iter < MAX_ITER)
			{
				mlx->z = complex(pow(mlx->z.re, 2.0) - pow(mlx->z.im, 2.0)
						+ mlx->k.re, 2.0 * mlx->z.re * mlx->z.im + mlx->k.im);
				if ((mlx->z.re * mlx->z.re) + (mlx->z.im * mlx->z.im) > 4.0)
				{
					pxl(mlx, mlx->x, mlx->y, color(mlx->iter, mlx->z, mlx));
					break ;
				}
				else
					pxl(mlx, mlx->x, mlx->y, 0x000000);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
