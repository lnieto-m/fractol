/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:42:50 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/26 16:12:53 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		pointer_motion(int x, int y, t_env *e)
{
	e->mem_a = x;
	e->mem_b = y;
	return (0);
}