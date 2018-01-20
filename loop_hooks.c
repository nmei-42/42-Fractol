/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:54:39 by nmei              #+#    #+#             */
/*   Updated: 2018/01/18 23:48:32 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

/*
**	loop_hook()
**	This loop hook is necessary for psychedelic mode which changes the phase
**	of the rgb sin waves so that colors will undulate.
**
**	We want the relative phase relation between r, g, and b to remain the same
**	so we add the same amount to each phase. If a phase offset goes over 2*PI
**	Then we need to take the float modulus so that it's back in range of our
**	2*PI limit.
**
**	Special thanks to Igor Karishev a fellow cadet @ 42 USA for the
**	inspiration to create Psychedelic mode!
*/

int		loop_hook(t_envars *env)
{
	t_color	*c;

	if (env->psychedelic == 1)
	{
		c = &env->c;
		c->r_phase = (c->r_phase > 2 * M_PI) ?
		fmod(c->r_phase, 2 * M_PI) : c->r_phase + 0.05;
		c->g_phase = (c->g_phase > 2 * M_PI) ?
		fmod(c->g_phase, 2 * M_PI) : c->g_phase + 0.05;
		c->b_phase = (c->b_phase > 2 * M_PI) ?
		fmod(c->b_phase, 2 * M_PI) : c->b_phase + 0.05;
		render(env);
	}
	return (0);
}
