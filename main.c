/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:52:48 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:51:52 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>
#include "fractol.h"

static void		disp_info(int mode)
{
	if (mode == 0)
	{
		write(2, "Usage: ./fractol [fractol option]\n\n", 35);
		write(2, "Fractol options (use number, not name!):\n", 41);
		write(2, "0) Julia\n1) Mandelbrot\n2) Burning Ship\n", 39);
		write(2, "3) Trijulia\n4) Tribrot\n5) Excalibur\n", 36);
		write(2, "6) Quadjulia\n7) Quadrobrot\n8) Ghosts\n", 36);
		write(2, "\nExample: './fractol 0' - Displays Julia set\n\n", 46);
	}
	else if (mode == 1)
	{
		ft_putstr("\n				Fract'ol 42!!\n\
		Mouse scroll up/down: Zoom in/out @ mouse position\n\
		Arrow keys: Translate real/imaginary axes\n\
		'+/-': Increase/decrease iteration limit\n\
		f: Freeze mouse cursor tracking (only works for Julia type fractals!)\n\
		p: Psychedelic mode!\n\
		l: linear continous color mode\n\
		c: Toggle color palettes\n\
		s: Color surprise!\n\
		d: Psychedelic surprise!\n\
		r: Reset active fractal!\n\
		esc: Quit :(\n\n");
	}
}

void			start_hooks(t_envars *env)
{
	mlx_key_hook(env->win, keydown_hook, env);
	mlx_hook(env->win, 2, 0, key_pressed_hook, env);
	mlx_hook(env->win, 4, 0, mouse_pressed_hook, env);
	mlx_hook(env->win, 5, 0, mouse_released_hook, env);
	mlx_hook(env->win, 6, 0, mouse_moved_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
}

void			setup_env(t_envars *env)
{
	env->w = 1024;
	env->h = 576;
	env->size = env->w * env->h;
	env->x_t = 0;
	env->y_t = 0;
	env->ccolor = 0;
	env->iter_lim = 50;
	env->iter_buf = (float *)malloc(env->size * sizeof(float));
	env->fract_setup(env);
	setup_color(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w, env->h, "Fractol 42");
	init_img(env);
	init_mouse(env);
	start_hooks(env);
	render(env);
	mlx_loop(env->mlx);
}

/*
**	main - function where we start our mlx session
**	There are additional hooks that can be found!
**	See: https://github.com/qst0/ft_libgfx
**	Of particular interest are the mouse press, release, and movement hooks
**	which are mapped to 4, 5, and 6 respectively.
*/

int				main(int argc, char *argv[])
{
	t_envars	env;

	env.fract_choice = -1;
	if (argc == 2 && (env.fract_choice = get_fract_funct(&env, argv[1])) != -1)
	{
		disp_info(1);
		setup_env(&env);
		return (0);
	}
	else
	{
		disp_info(0);
		return (1);
	}
}
