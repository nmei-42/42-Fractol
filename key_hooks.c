/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:28:08 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 14:03:21 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "fractol.h"

static void	cleanup_env(t_envars *env)
{
	free(env->iter_buf);
	mlx_destroy_image(env->mlx, (&env->image)->image);
	mlx_destroy_window(env->mlx, env->win);
}

void		reset_env(t_envars *env)
{
	cleanup_env(env);
	setup_env(env);
}

/*
**	keydown_hook - similar to key_pressed_hook but will only be called when
**	a key has been pressed AND released.
**
**	The following key are mapped:
**	'esc' (53) = quit the program
**	'p' (35) = PsYcHeDeLiC MoDe!!
**	'c'	(8) = toggle color modes
**	's' (1) = color surprise!
**	'd' (2) = psychedelic surprise!
**	'l'	(37) = linear continous color mode
**	'f' (3) = Stop mouse cursor tracking for interactive fractals
**	'r' (15) = reset the fractal back to original window size, iter limits, and
**	color palette
*/

int			keydown_hook(int key, t_envars *env)
{
	if (key == 53)
	{
		cleanup_env(env);
		exit(0);
	}
	if (key == 35)
		env->psychedelic = (env->psychedelic) ? 0 : 1;
	if (key == 8)
		toggle_palette(env);
	if (key == 1)
		color_surprise(env);
	if (key == 2)
		psychedelic_surprise(env);
	if (key == 37 && env->psychedelic == 0)
		env->ccolor = (env->ccolor) ? 0 : 1;
	if (key == 3)
		env->mouse.freeze = (env->mouse.freeze) ? 0 : 1;
	if (key == 15)
		reset_env(env);
	if (key == 37 || key == 15 || key == 8 || key == 1)
		render(env);
	return (0);
}

/*
**	key_pressed_hook - while any of the arrow keys on the keyboard are
**	held down, shift the map in that direction.
**
**	← (123) = translate x left inversely proportional to the zoom
**	→ (124) = translate x right inversely proportional to the zoom
**	↓ (125) = translate y down inversely proportional to the zoom
**	↑ (126) = translate y up inversely proportional to the zoom
*/

int			key_pressed_hook(int key, t_envars *env)
{
	if (env->psychedelic == 0 && key != 53)
	{
		if (key == 124)
			env->x_t -= (0.05 / env->f.z_factor);
		if (key == 123)
			env->x_t += (0.05 / env->f.z_factor);
		if (key == 126)
			env->y_t += (0.05 / env->f.z_factor);
		if (key == 125)
			env->y_t -= (0.05 / env->f.z_factor);
		if (key == 24)
			env->iter_lim += 10;
		if (key == 27)
			env->iter_lim -= (env->iter_lim > 10) ? 10 : 0;
		render(env);
	}
	return (0);
}
