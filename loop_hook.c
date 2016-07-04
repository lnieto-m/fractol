/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:05:27 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/26 18:22:02 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			loop_hook(t_env *e)
{
	static int	a = 450;
	static int	b = 300;

	if (ft_strcmp(e->fractale, "julia") == 0 && e->it == 0)
	{
		e->c_x += (e->mem_a - a) * 0.01;
		e->c_y += (e->mem_b - b) * 0.005;
		expose_hook(e);
	}
	a = e->mem_a;
	b = e->mem_b;
	return (0);
}
