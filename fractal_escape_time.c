/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_escape_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:00:29 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:12:59 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

/*
**	calc_z() and escape_time()
**	Classic escape time algorithm for determining fractal color
**	For Mandelbrot and Multibrot series, a given point will escape to infinity
**	if the absolute value of the complex number is greater than 2.0
**
**	Z(n+1) = Z(n)^d + c where d = 2 for the simplest case Mandelbrot
**
**	Thus to find if a given point is in the mandelbrot set we repeat:
**	Z(n+1) = Z(n)^2 + c
**	(Where n is the current iteration and n+1 is the next iteration)
**	and continue until we've found |Z(n+1)| > 2.0
**
**	To simplify for the computer we can check if |Z(n+1)|^2 <= 4.0
**
**	We also want to avoid too many multiplications since they are very expensive
**	at high precisions. To get Z(n+1) we would need to evaluate
**
**	'Z(n)^2 + c' where 'Z(n) = a + bi' which would give us:
**	'a^2 - b^2 + 2abi + c'
**
**	To isolate the imaginary component we subtract a^2 and b^2 this will leave
**	us with '2abi' which we would then just add the imaginary component of c.
**
**	To isolate the real component we just use the a^2 - b^2 we had previously
**	calculated and then just add the real component of c
**
**	These tricks are detailed in:
** 	https://randomascii.wordpress.com/2011/08/13/faster-fractals-through-algebra
**
**	Another trick we can play is to check if our real and imaginary components
**	after squaring are equal to a previous iteration. If so, we've hit a cycle
**	and our point is in the Mandelbrot set saving us previous iteration
**	time!!
**
**	To get smooth coloring we can apply a log log transformation to Z(n)
**	The idea is that because each iteration of Z goes like:
**	Z^2 -> Z^4 -> Z^8 -> Z^16 -> Z^32
**	Applying 1 log transformation allows us to bring the exponent in front:
**	2*log(Z) -> 4*log(Z) -> 8*log(Z) -> 16*log(Z) -> 32*log(Z)
**	Applying a 2nd log transformation with **change of base** will then give:
**	0 -> 1 -> 2 -> 3 -> 4
**
**	A more in depth explanation can be found:
**	http://linas.org/art-gallery/escape/escape.html
*/

void	calc_z(t_envars *env, t_dcmplx *tmp_z, t_dcmplx z, t_dcmplx c)
{
	if (env->f.d == 2)
	{
		tmp_z->i = (z.r + z.i) * (z.r + z.i) - z.rsqr - z.isqr + c.i;
		tmp_z->r = z.rsqr - z.isqr + c.r;
	}
	else if (env->f.d == 3)
	{
		tmp_z->i = z.i * (3 * z.rsqr - z.isqr) + c.i;
		tmp_z->r = z.r * (z.rsqr - 3 * z.isqr) + c.r;
	}
	else if (env->f.d == 4)
	{
		tmp_z->i = (4 * z.r * z.i) * (z.rsqr - z.isqr) + c.i;
		tmp_z->r = (z.rsqr * z.rsqr) + z.isqr * (z.isqr - 6 * z.rsqr) + c.r;
	}
	if (env->f.abs == 1)
	{
		tmp_z->i = (tmp_z->i < 0.0f) ? -tmp_z->i : tmp_z->i;
		tmp_z->r = (tmp_z->r < 0.0f) ? -tmp_z->r : tmp_z->r;
	}
}

float	escape_time(t_envars *env, t_fractal f)
{
	size_t		iter;
	t_dcmplx	z;
	t_dcmplx	c;
	t_dcmplx	tmp_z;

	z = f.z;
	c = f.c;
	iter = 0;
	z = abs_sqr(z);
	while (z.rsqr + z.isqr <= 4.0 && iter < env->iter_lim)
	{
		calc_z(env, &tmp_z, z, c);
		if (z.r == tmp_z.r && z.i == tmp_z.i)
		{
			iter = env->iter_lim;
			break ;
		}
		z = abs_sqr(tmp_z);
		iter++;
	}
	if (env->ccolor == 1 && iter != env->iter_lim)
		return ((float)iter + 1 - log(log(z.rsqr + z.isqr)) / log(env->f.d));
	return ((float)iter);
}
