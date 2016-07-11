/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 20:33:43 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/31 15:47:05 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter(t_coords c, t_env *e)
{
	t_coords	z;
	t_coords	r;
	int			a;

	z.x = 0;
	z.y = 0;
	r.x = 0;
	r.y = 0;
	a = 0;
	while (a < e->iteration)
	{
		r.x = z.x;
		r.y = z.y;
		z.x = (fabs(r.x) * fabs(r.x) - fabs(r.y) * fabs(r.y)) + c.x;
		z.y = 2 * fabs(r.x) * fabs(r.y) + c.y;
		if (sqrt(z.x * z.x + z.y * z.y) >= 4)
			break ;
		a++;
	}
	return (a);
}

void		burning_ship(t_env *e)
{
	t_point			coord;
	t_coords		c;
	int				a;
	int				color;
	const double	n = 127.5;

	c.x = 0;
	c.y = 0;
	coord.x = 0;
	coord.y = 0;
	a = 0;
	while (coord.x++ < e->x)
	{
		while (coord.y++ < e->y)
		{
			c.x = e->b_x.x + (e->b_x.y - e->b_x.x) / e->x * 4 * coord.x;
			c.y = e->b_y.x + (e->b_y.y - e->b_y.x) / e->y * coord.y;
			a = iter(c, e);
			color = RGB(n * (cos(a) + 1), n * (sin(a) + 1), n * (1 - cos(a)));
			image_pixel_put(e, coord, color);
		}
		coord.y = 0;
	}
}
