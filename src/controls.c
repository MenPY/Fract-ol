/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:35 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:36 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	zoom(t_data *fr, int key)
{
	double	i;

	if (key == KB_X || key == MWHEELUP)
		fr->zoom = 1.15;
	else
		fr->zoom = 1.0 / 1.15;
	i = 1.0 / fr->zoom;
	fr->min.re = interpolate(fr->mpos.re, fr->min.re, i);
	fr->min.im = interpolate(fr->mpos.im, fr->min.im, i);
	fr->max.re = interpolate(fr->mpos.re, fr->max.re, i);
	fr->max.im = interpolate(fr->mpos.im, fr->max.im, i);
}

void	move(t_data *fr, int key)
{
	if (key == KB_LEFT)
	{
		fr->min.re -= 0.1;
		fr->max.re = fr->min.re + (fr->max.im - fr->min.im);
	}
	else if (key == KB_RIGHT)
	{
		fr->min.re += 0.1;
		fr->max.re = fr->min.re + (fr->max.im - fr->min.im);
	}
	else if (key == KB_UP)
	{
		fr->min.im += 0.1;
		fr->max.im = fr->min.im + (fr->max.re - fr->min.re);
	}
	else if (key == KB_DOWN)
	{
		fr->min.im -= 0.1;
		fr->max.im = fr->min.im + (fr->max.re - fr->min.re);
	}
}

int	key_handler(int keycode, t_data *fr)
{
	if (keycode == KB_ESC)
		exit(0);
	else if (keycode == KB_X || keycode == KB_Z)
		zoom(fr, keycode);
	else if (keycode == KB_RIGHT || keycode == KB_DOWN
		|| keycode == KB_LEFT || keycode == KB_UP)
		move(fr, keycode);
	else if (keycode == KB_R)
		reset_fractol(fr);
	else if (keycode == KB_F)
	{
		fr->mode += 1;
		if (fr->mode == 6)
			fr->mode = 0;
	}
	else if (keycode == KB_J)
		fr->julia_fixed = !fr->julia_fixed;
	if (fr->fractol == 1)
		mandelbrot(fr);
	else if (fr->fractol == 2)
		julia(fr);
	return (0);
}

int	mouse_mandelbrot(int key, int mx, int my, t_data *fr)
{
	if (key == 4 || key == 5)
	{
		fr->mpos = complex(mx / (W / (fr->max.re - fr->min.re))
				+ fr->min.re, my / -(H / (fr->max.im - fr->min.im))
				+ fr->max.im);
		zoom(fr, key);
		if (fr->fractol == 1)
			mandelbrot(fr);
		else if (fr->fractol == 2)
			julia(fr);
	}
	return (0);
}

int	mouse_julia(int mx, int my, t_data *fr)
{
	if (fr->julia_fixed == 0)
	{
		fr->k = complex(4 * ((float)mx / W - 0.5),
				4 * ((float)(H - my) / H - 0.5));
		julia(fr);
	}
	fr->mpos = complex(mx, my);
	return (0);
}
