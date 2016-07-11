/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:58:55 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/25 19:01:07 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	inter(int keycode, t_env *e)
{
	if (keycode == 69 && e->iteration + 20 < 2147483647)
	{
		e->iteration += 20;
		expose_hook(e);
	}
	if (keycode == 78 && e->iteration - 20 > 0)
	{
		e->iteration -= 20;
		expose_hook(e);
	}
	if (keycode == 49)
	{
		if (e->it == 1)
			e->it = 0;
		else
			e->it = 1;
	}
}

int			key_r(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		if (ft_strcmp("julia", e->fractale) == 0)
		{
			e->c_x = 0;
			e->c_y = 0;
		}
		e->b_x.x = -2.4;
		e->b_x.y = 2.4;
		e->b_y.x = -1.5;
		e->b_y.y = 1.5;
		expose_hook(e);
	}
	inter(keycode, e);
	if (keycode == 53)
	{
		free(e->fractale);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
