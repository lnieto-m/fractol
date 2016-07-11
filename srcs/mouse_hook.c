/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:34:18 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/31 14:58:48 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pro(t_coords now1, t_coords now2, t_coords d, t_env *e)
{
	e->b_x.x = d.x - (now1.y - now1.x);
	e->b_x.y = d.x + (now1.y - now1.x);
	e->b_y.x = d.y - (now2.y - now2.x);
	e->b_y.y = d.y + (now2.y - now2.x);
	expose_hook(e);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	const double	min = 0.00000000000001;
	t_coords		d;
	t_coords		now1;
	t_coords		now2;

	now1.x = e->b_x.x;
	now1.y = e->b_x.y;
	now2.x = e->b_y.x;
	now2.y = e->b_y.y;
	d.x = now1.x + x * (now1.y - now1.x) / e->x * 4;
	d.y = now2.x + y * (now2.y - now2.x) / e->y;
	if (button == 4 && (e->b_x.y - e->b_x.x) > min
		&& (e->b_y.y - e->b_y.x) > min)
	{
		e->b_x.x = d.x - (now1.y - now1.x) / 4;
		e->b_x.y = d.x + (now1.y - now1.x) / 4;
		e->b_y.x = d.y - (now2.y - now2.x) / 4;
		e->b_y.y = d.y + (now2.y - now2.x) / 4;
		expose_hook(e);
	}
	else if (button == 5)
		pro(now1, now2, d, e);
	return (0);
}
