/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:44 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:45 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	reset_fractol(t_data *fr)
{
	fr->zoom = 1.0;
	fr->mode = 0;
	fr->max.re = 2.0;
	fr->min.im = -2.0;
	fr->min.re = -2.0;
	fr->julia_fixed = 0;
	fr->max.im = fr->min.im + (fr->max.re - fr->min.re);
	fr->k = complex(-0.4, 0.6);
}

t_rgb	mode_0(t_rgb rgb)
{
	if (rgb.v < 1.0)
	{
		rgb.r = pow(rgb.v, 4);
		rgb.g = pow(rgb.v, 2.5);
		rgb.b = rgb.v;
	}
	else
	{
	rgb.v = mymax(0.0, 2.0 - rgb.v);
	rgb.r = rgb.v;
	rgb.g = pow(rgb.v, 1.5);
	rgb.b = pow(rgb.v, 3);
	}
	return (rgb);
}

t_complex	complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

double	mymax(double a, double b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}
