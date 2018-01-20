/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:40:26 by nmei              #+#    #+#             */
/*   Updated: 2018/01/18 22:50:09 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fractol.h"

/*
**	init_img - use mlx functions to initialize our image that we will be
**	drawing our maps on!
**
**	The initial bits per pixel (bpp) that the mlx_get_data_addr function returns
**	is 32 bits.
**
**	We would like to work with bytes though since that's what the rest of our
**	program is working in.
**
**	Example 1: our colors are ints which are in bytes.
**	Example 2: Our ft_bzero and ft_memset functions expect a size in bytes
**
**	Since 8 bits = 1 byte we just take our bpp and divide by 8 to get
**	BYTES per pixel
**
**	LET IT BE DECLARED HERE THAT img->bpp HENCEFORCE STANDS FOR BYTES PER PIXEL!
*/

void		init_img(t_envars *env)
{
	t_image	*img;

	img = &env->image;
	img->image = mlx_new_image(env->mlx, env->w, env->h);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_s,
								&img->endian);
	img->bpp /= 8;
}

void		img_pixel_put(t_envars *env, double x, double y, int color)
{
	t_image *img;

	img = &(env->image);
	if (x >= 0 && x < env->w && y >= 0 && y < env->h)
		*(int *)(img->ptr + (int)(idx(y, x, env->w) * img->bpp)) = color;
}

/*
**	Our image is WIN_W * WIN_H * 32 bits per pixel large.
**	Our ft_bzero and ft_memset functions take a size in BYTES though...
*/

void		clear_img(t_envars *env)
{
	t_image *img;

	img = &(env->image);
	ft_bzero(img->ptr, env->size * img->bpp);
}
