/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:52:31 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:13:06 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	mandelbrot()
**	Basic mandelbrot set where 'c' is determined based on a pixel's location
**	in a bounded area (see: fractal_setup_?.c functions to derive bounds)
*/

void			mandelbrot(void *environ, int pix_ind)
{
	t_fractal	f;
	t_envars	*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	if (env->psychedelic == 0)
	{
		f = calc_fract_min_max(env, f);
		env->f = f;
		f.c.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
		f.c.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
		f.z.r = 0;
		f.z.i = 0;
		env->iter_buf[pix_ind] = escape_time(env, f);
	}
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}

/*
**	julia()
**	The julia set is *extremely* similar to the mandelbrot set
**	The only difference is that the c value is determined by the position of the
**	mouse cursor. That's literally the only difference...
*/

void			julia(void *environ, int pix_ind)
{
	t_fractal	f;
	t_envars	*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	if (env->psychedelic == 0)
	{
		f = calc_fract_min_max(env, f);
		env->f = f;
		f.c.r = ft_lint(-f.x_wid / 2, f.x_wid / 2, env->mouse.x / env->w);
		f.c.i = ft_lint(-f.y_wid / 2, f.y_wid / 2, env->mouse.y / env->h);
		f.z.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
		f.z.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
		env->iter_buf[pix_ind] = escape_time(env, f);
	}
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}
