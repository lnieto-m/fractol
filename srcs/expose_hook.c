/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:00:34 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/25 13:49:11 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_env *e)
{
	if (ft_strcmp(e->fractale, "mandelbrot") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->fractale, "julia") == 0)
		julia(e);
	else if (ft_strcmp(e->fractale, "burning_ship") == 0)
		burning_ship(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
