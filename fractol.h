/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:55:53 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/26 18:21:38 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_coords
{
	double			x;
	double			y;
}					t_coords;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data_img;
	int				bpp;
	int				end;
	int				x;
	int				x_min;
	int				y;
	int				y_min;
	int				a;
	int				b;
	int				iteration;
	int				it;
	int				mem_a;
	int				mem_b;
	double			c_x;
	double			c_y;
	char			*fractale;
	t_coords		b_x;
	t_coords		b_y;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					key_r(int keycode, t_env *e);
int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					pointer_motion(int x, int y, t_env *e);
int					image_pixel_put(t_env *e, t_point a, int color);
void				mandelbrot(t_env *e);
void				julia(t_env *e);
void				burning_ship(t_env *e);
int					loop_hook(t_env *e);

#endif
