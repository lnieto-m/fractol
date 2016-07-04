/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:29:16 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/25 13:13:36 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter(t_env *e, t_coords z)
{
	int			a;
	t_coords	r;

	a = 0;
	r.x = 0;
	r.y = 0;
	while (a < e->iteration)
	{
		r.x = z.x;
		r.y = z.y;
		z.x = (r.x * r.x) - (r.y * r.y) + e->c_x;
		z.y = 2 * r.x * r.y + e->c_y;
		if (sqrt((z.x * z.x) + (z.y * z.y)) >= 2)
			break ;
		a++;
	}
	return (a);
}

void		julia(t_env *e)
{
	t_point			coord;
	t_coords		z;
	int				a;
	int				color;
	const double	n = 127.5;

	a = 0;
	color = 0;
	z.x = 0;
	z.y = 0;
	coord.x = 0;
	coord.y = 0;
	while (coord.x++ < e->x)
	{
		while (coord.y++ < e->y)
		{
			z.x = e->b_x.x + (e->b_x.y - e->b_x.x) / e->x * 4 * coord.x;
			z.y = e->b_y.x + (e->b_y.y - e->b_y.x) / e->y * coord.y;
			a = iter(e, z);
			color = RGB(n * (cos(a) + 1), n * (sin(a) + 1), n * (1 - cos(a)));
			image_pixel_put(e, coord, color);
		}
		coord.y = 0;
	}
}
