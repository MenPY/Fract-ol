/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:29 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:30 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	pxl(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_rgb	colormode(int mode, int iteration, t_complex z, t_rgb rgb)
{
	rgb.v = log(iteration + 6 - log(log(log(fabs(pow(z.im, 2))
						+ fabs(pow(z.re, 2)))))) / 3.4;
	if (mode == 1)
		return (mode_1(rgb));
	else if (mode == 2)
		return (mode_2(rgb));
	else if (mode == 3)
		return (mode_3(rgb));
	else if (mode == 4)
		return (mode_4(rgb));
	else if (mode == 5)
		return (mode_5(rgb));
	else
		return (mode_0(rgb));
}

double	color(int iteration, t_complex z, t_data *fr)
{
	t_rgb	rgb;
	double	color;

	rgb = colormode(fr->mode, iteration, z, rgb);
	color = create_trgb(0, rgb.r * 255, rgb.g * 255, rgb.b * 255);
	return (color);
}
