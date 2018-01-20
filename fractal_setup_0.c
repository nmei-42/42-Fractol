/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_setup_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:48:26 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 12:48:18 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	setup_fract()
**	Initializes the zoom factor, center 'x, y' coordinates of our fractal as
**	well as the width of our x and y dimensions.
*/

void	setup_julia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_mandelbrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = -0.5;
	env->f.y_cent = 0.0;
	env->f.x_wid = 3.5;
	env->f.y_wid = 2.5;
}

void	setup_bship(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = -0.5;
	env->f.y_cent = -0.25;
	env->f.x_wid = 3.0;
	env->f.y_wid = 3.0;
}

void	setup_trijulia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 3;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_tribrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 3;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 3;
}
