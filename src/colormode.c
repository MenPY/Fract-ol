/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:25 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:26 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_rgb	mode_1(t_rgb rgb)
{
	if (rgb.v < 1.0)
	{
		rgb.r = pow(rgb.v, 200.5);
		rgb.g = pow(rgb.v, 5.5);
		rgb.b = rgb.v;
	}
	else
	{
		rgb.v = mymax(0.0, 2.0 - rgb.v);
		rgb.r = rgb.v;
		rgb.g = pow(rgb.v, 0.5);
		rgb.b = pow(rgb.v, 2.9);
	}
	return (rgb);
}

t_rgb	mode_2(t_rgb rgb)
{
	if (rgb.v < 1.0)
	{
		rgb.r = pow(rgb.v, 4);
		rgb.g = pow(rgb.v, 6.5);
		rgb.b = rgb.g;
	}
	else
	{
		rgb.v = mymax(0.0, 2.0 - rgb.v);
		rgb.r = rgb.v;
		rgb.g = pow(rgb.v, 1.5);
		rgb.b = pow(rgb.v, 30);
	}
	return (rgb);
}

t_rgb	mode_3(t_rgb rgb)
{
	if (rgb.v < 100)
	{
		rgb.r = pow(rgb.v, 200.5);
		rgb.g = pow(rgb.v, 5.5);
		rgb.b = pow(rgb.v, 16);
	}
	else
	{
		rgb.v = mymax(0.0, 2.0 - rgb.v);
		rgb.r = rgb.v;
		rgb.g = pow(rgb.v, 0.5);
		rgb.b = pow(rgb.v, 2);
	}
	return (rgb);
}

t_rgb	mode_4(t_rgb rgb)
{
	if (rgb.v < 100)
	{
		rgb.r = pow(rgb.v, -20.5);
		rgb.g = pow(rgb.v, 20.5);
		rgb.b = pow(rgb.v, -23);
	}
	else
	{
		rgb.v = mymax(0.0, 2.0 - rgb.v);
		rgb.r = rgb.v;
		rgb.g = pow(rgb.v, 9.5);
		rgb.b = pow(rgb.v, 23);
	}
	return (rgb);
}

t_rgb	mode_5(t_rgb rgb)
{
	if (rgb.v < 1.0)
	{
		rgb.r = pow(rgb.v, -16.5);
		rgb.g = pow(rgb.v, -290.5);
		rgb.b = rgb.v + 5;
	}
	else
	{
		rgb.v = mymax(0.0, 2.0 - rgb.v);
		rgb.r = rgb.v;
		rgb.g = pow(rgb.v, 90.5);
		rgb.b = pow(rgb.v, -23);
	}
	return (rgb);
}
