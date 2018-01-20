/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:04 by nmei              #+#    #+#             */
/*   Updated: 2018/01/18 23:49:10 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	idx() - Useful function to get the row, col value from a flattened
**	2D matrix. Dim is the 'width' of the matrix...
*/

int			idx(int row, int col, int dim)
{
	return (row * dim + col);
}

/*
**	ft_lint - Linear INTerpolation between two points given a decimal percent
**
**	We don't do: (start + decimal_percent * (end - start)) because if
**	start and end differ significantly in magnitude then we lose precision.
**
**	Test with: ft_lint(-16.0e30, 16.0, 1.0)
*/

double		ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
}

/*
**	abs_sqr()
**	Perform absolute squared of our complex number
**	Recall for a complex number z where z = a + bi that the absolute value of z:
**	|z| = sqrt(a^2  + b^2)
**	Because square root is an expensive operation for computer if we take the
**	absolute value squared we get:
**	|z|^2 = a^2 + b^2
*/

t_dcmplx	abs_sqr(t_dcmplx z)
{
	z.rsqr = (z.r * z.r);
	z.isqr = (z.i * z.i);
	return (z);
}

/*
**	calc_fract_min_max()
**	Calculate the minimum and maximum extents of our fractal. These extents
**	can then be used to interpolate the (real, imag) coordinates for each
**	of the pixels in our window.
**
**	To get zooming to work correctly (like in Google maps):
**	1) We scale our x and y widths by our desired zoom factor
**	2) We set our x_min as the center point of our fractal + any offsets
**	   and subtract by the width multiplied by the 'x_ratio' of our mouse cursor
**	3) Our x_max is similar except we multiply by '1 - x_ratio'
**	4) Repeat 2) && 3) but for y_min and y_max
**
**	Multiplying by the mouse cursor ratio will accordingly scale the left
**	width and right width of the fractal such that the cursor position will
**	will remain in the same spot even in our newly zoomed image.
**
**	The finishing puzzle piece is that we set the x_center and y_center
**	to the interpolated position of the mouse cursor when the zoom scroll
**	was initiated. (see: mouse_hooks.c)
*/

t_fractal	calc_fract_min_max(t_envars *env, t_fractal f)
{
	double	x_wid;
	double	y_wid;

	x_wid = f.x_wid / env->f.z_factor;
	y_wid = f.y_wid / env->f.z_factor;
	f.x_min = f.x_cent + env->x_t - x_wid * (env->mouse.x_ratio);
	f.x_max = f.x_cent + env->x_t + x_wid * (1 - env->mouse.x_ratio);
	f.y_min = f.y_cent + env->y_t - y_wid * (env->mouse.y_ratio);
	f.y_max = f.y_cent + env->y_t + y_wid * (1 - env->mouse.y_ratio);
	return (f);
}
