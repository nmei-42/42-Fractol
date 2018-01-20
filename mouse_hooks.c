/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:16:38 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 12:43:58 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mouse(t_envars *env)
{
	t_mouse		*new_mouse;

	new_mouse = &env->mouse;
	new_mouse->is_pressed = 0;
	new_mouse->freeze = 0;
	new_mouse->prev_x = 0;
	new_mouse->prev_y = 0;
	new_mouse->x = 0;
	new_mouse->y = 0;
	new_mouse->x_ratio = 0.5;
	new_mouse->y_ratio = 0.5;
}

/*
**	mouse_pressed_hook - hook for the mouse pressed event that is passed to
**	mlx_hook(). mlx_hook() will pass "int button, int x, int y" followed by
**	any params also passed to mlx_hook() to the function when the mouse is
**	pressed.
**
**	Button can take on multiple values!!!
**	1 = mouse left button click
**	2 = mouse right button click
**	3 = ????? (maybe clicking the scroll wheel???)
**	4 = mouse scroll wheel down - decrease the zoom factor
**	5 = mouse scroll wheel up - increase the the zoom factor
**	6 = mouse scroll wheel right
**	7 = mouse scroll wheel left
**
**	NOTE: all x and y coordinates reported to the mouse hook functions will
**	have (0, 0) being the BOTTOM LEFT CORNER of the window. (WIN_W, WIN_H) will
**	thus be the TOP RIGHT CORNER of the window... which is completely different
**	from the image's (0,0) which is TOP LEFT CORNER... go figure...
**
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X & Y FROM INT TO DOUBLE!!
**	Doing so will corrupt the addressing of your params and give you segfaults
**	that will take you possibly hours to debug (at least for me...)
*/

int		mouse_pressed_hook(int button, int x, int y, t_envars *env)
{
	double		fx;
	double		fy;
	t_mouse		*mouse;

	mouse = &env->mouse;
	if (x >= 0 && x <= env->w && y >= 0 && y <= env->h)
	{
		if (button == 4 || button == 5)
		{
			mouse->x_ratio = (double)x / env->w;
			mouse->y_ratio = (double)y / env->h;
			fx = ft_lint(env->f.x_min, env->f.x_max, mouse->x_ratio);
			fy = ft_lint(env->f.y_min, env->f.y_max, mouse->y_ratio);
			if (button == 4)
				env->f.z_factor /= 1.1;
			if (button == 5)
				env->f.z_factor *= 1.1;
			env->f.x_cent = fx;
			env->f.y_cent = fy;
			env->x_t = 0;
			env->y_t = 0;
			render(env);
		}
	}
	return (0);
}

/*
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X & Y FROM INT TO DOUBLE!!
*/

int		mouse_released_hook(int button, int x, int y, t_envars *env)
{
	t_mouse		*mouse;

	mouse = &env->mouse;
	(void)button;
	(void)x;
	(void)y;
	mouse->is_pressed = 0;
	return (0);
}

/*
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X & Y FROM INT TO DOUBLE!!
*/

int		mouse_moved_hook(int x, int y, t_envars *env)
{
	t_mouse		*mouse;
	int			f_i;

	mouse = &env->mouse;
	f_i = env->f.interactive;
	if (mouse->freeze == 0 && (x >= 0 && x <= env->w && y >= 0 && y <= env->h))
	{
		mouse->prev_x = mouse->x;
		mouse->prev_y = mouse->y;
		mouse->x = x;
		mouse->y = y;
		if (env->psychedelic == 0 && f_i == 1)
			render(env);
	}
	return (0);
}
