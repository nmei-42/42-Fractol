/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:08:32 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:59:39 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fractol.h"

void	setup_color(t_envars *env)
{
	env->color_style = 0;
	env->c.cent = 127;
	env->c.wid = 128;
	env->c.r_freq = 0.33;
	env->c.g_freq = 0.33;
	env->c.b_freq = 0.33;
	env->c.r_phase = 0.00;
	env->c.g_phase = (2 * M_PI) / 3;
	env->c.b_phase = (4 * M_PI) / 3;
	env->psychedelic = 0;
}

void	toggle_palette(t_envars *env)
{
	env->color_style = (env->color_style + 1) % 4;
	if (env->color_style == 0)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 1)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.00;
	}
	if (env->color_style == 2)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.00;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 3)
	{
		env->c.r_freq = 0.00;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
}

void	color_surprise(t_envars *env)
{
	env->c.r_freq = rand() % 10;
	env->c.g_freq = rand() % 10;
	env->c.b_freq = rand() % 10;
}

void	psychedelic_surprise(t_envars *env)
{
	env->c.r_phase = rand() % 20;
	env->c.g_phase = rand() % 20;
	env->c.b_phase = rand() % 20;
}

/*
** choose_col()
** Let's use some math magic to generate some pretty colors!
** By using a sin wave and shifting the frequency and phase of r, g, b
** color components we can generate regular repeating color gradients!
**
** The center of our color range is 127 (because 255 is max)
** Thus the width of our color range is 128 (if we want rainbow effects)
** Heavily inspired by: https://krazydad.com//tutorials/makecolors.php
*/

int		choose_col(t_envars *env, float iter)
{
	int		r;
	int		g;
	int		b;
	t_color	c;

	c = env->c;
	if (iter >= env->iter_lim)
		return (0);
	else
	{
		r = sin(fmod(c.r_freq * iter + c.r_phase, 2 * M_PI)) * c.wid + c.cent;
		g = sin(fmod(c.g_freq * iter + c.g_phase, 2 * M_PI)) * c.wid + c.cent;
		b = sin(fmod(c.b_freq * iter + c.b_phase, 2 * M_PI)) * c.wid + c.cent;
		return (r << 16 | g << 8 | b);
	}
}
