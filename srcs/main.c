/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:55:31 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/26 18:21:45 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		def(t_env *e, char *av)
{
	e->x = 900;
	e->y = 600;
	e->x_min = 0;
	e->y_min = 0;
	e->end = 1;
	e->bpp = 8;
	e->c_x = 0;
	e->c_y = 0;
	e->it = 0;
	e->fractale = ft_strdup(av);
	if (ft_strcmp("julia", e->fractale) == 0)
		e->iteration = 80;
	else if (ft_strcmp("mandelbrot", e->fractale) == 0)
		e->iteration = 50;
	else
		e->iteration = 20;
	e->a = 0;
	e->b = 0;
	e->b_x.x = -2.4;
	e->b_x.y = 2.4;
	e->b_y.x = -1.5;
	e->b_y.y = 1.5;
	e->mem_a = 0;
	e->mem_b = 0;
}

static void		print_choice(void)
{
	ft_putendl_fd("The parameter is not a valid type of fractal.", 1);
	ft_putendl_fd("Avalaible fractals : - mandelbrot", 1);
	ft_putendl_fd("                     - julia", 1);
	ft_putendl_fd("                     - burning_ship", 1);
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_env	e;

	if (ac != 2 || (ft_strcmp("julia", av[1]) != 0
		&& ft_strcmp("mandelbrot", av[1]) != 0
		&& ft_strcmp("burning_ship", av[1]) != 0))
		print_choice();
	def(&e, av[1]);
	if ((e.mlx = mlx_init()) == NULL
		|| (e.win = mlx_new_window(e.mlx, e.x, e.y, "Fract\'ol")) == NULL
		|| (e.img = mlx_new_image(e.mlx, e.x, e.y)) == NULL)
		exit(EXIT_FAILURE);
	e.data_img = (int *)mlx_get_data_addr(e.img, &e.bpp, &e.x, &e.end);
	mlx_hook(e.win, 3, (1L << 1), key_r, &e);
	mlx_hook(e.win, 6, (1L << 7), pointer_motion, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
