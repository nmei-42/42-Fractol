/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_setup_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:20:22 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 12:55:00 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	setup_excalibur()
**	It's actually the d = 3 version of burning ship...
**	But Excalibur sounds cooler >_>
*/

void	setup_excalibur(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 3;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_quadjulia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_quadrobrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 3;
}

void	setup_quadroship(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}
