/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesepoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:47:51 by mesepoya          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:52 by mesepoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include<fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define W		1000
# define H		1000
# define MAX_ITER	100

# ifdef __linux__
#  define KB_ESC		65307
#  define KB_X			120
#  define KB_Z			122
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KB_R			114
#  define KB_F			102
#  define KB_J			106 
# else
#  define KB_ESC		53
#  define KB_X			7
#  define KB_Z			6
#  define KB_UP			126
#  define KB_DOWN		125
#  define KB_LEFT		123
#  define KB_RIGHT		124
#  define KB_R			15
#  define KB_F			3
#  define KB_J			38
# endif
# define MWHEELUP		4
# define MWHEELDN		5

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_rgb{
	double	r;
	double	g;
	double	b;
	double	v;

}	t_rgb;

typedef struct s_data{
	t_complex	max;
	t_complex	min;
	t_complex	prop;
	t_complex	mpos;
	t_complex	k;
	t_rgb		rgb;
	t_complex	c;
	t_complex	z;

	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	char		*title;
	int			bits_per_pixel;
	int			fractol;
	int			line_length;
	int			endian;
	int			mode;
	int			julia_fixed;
	int			x;
	int			y;
	int			iter;
	double		zoom;
}	t_data;

double		interpolate(double start, double end, double interpolation);
t_rgb		colormode(int mode, int iteration, t_complex z, t_rgb rgb);
double		mymax(double a, double b);
t_complex	complex(double re, double im);
void		mandelbrot(t_data *mlx);
void		reset_fractol(t_data *fr);
static void	move(t_data *fr, int key);
int			key_handler(int keycode, t_data *fr);
static void	zoom(t_data *fr, int key);
void		pxl(t_data *data, int x, int y, unsigned int color);
int			mouse_mandelbrot(int key, int mx, int my, t_data *fr);
int			mouse_julia(int mx, int my, t_data *fr);
int			create_trgb(int t, int r, int g, int b);
double		color(int iteration, t_complex z, t_data *fr);
void		julia(t_data *mlx);
t_rgb		mode_0(t_rgb rgb);
t_rgb		mode_1(t_rgb rgb);
t_rgb		mode_2(t_rgb rgb);
t_rgb		mode_3(t_rgb rgb);
t_rgb		mode_4(t_rgb rgb);
t_rgb		mode_5(t_rgb rgb);

#endif
