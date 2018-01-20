/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:42:17 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:40:00 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stddef.h>
# include <pthread.h>

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_s;
	int			endian;
}				t_image;

typedef struct	s_mouse
{
	double		prev_x;
	double		prev_y;
	double		x;
	double		y;
	double		x_ratio;
	double		y_ratio;
	int			freeze;
	int			is_pressed;
}				t_mouse;

typedef struct	s_dcmplx
{
	double		r;
	double		i;
	double		rsqr;
	double		isqr;
}				t_dcmplx;

typedef struct	s_fractal
{
	t_dcmplx	z;
	t_dcmplx	c;
	int			d;
	int			x;
	int			y;
	int			abs;
	int			interactive;
	double		z_factor;
	double		x_cent;
	double		x_wid;
	double		x_min;
	double		x_max;
	double		y_cent;
	double		y_wid;
	double		y_min;
	double		y_max;
}				t_fractal;

typedef struct	s_color
{
	int			cent;
	int			wid;
	float		r_freq;
	float		g_freq;
	float		b_freq;
	float		r_phase;
	float		g_phase;
	float		b_phase;
}				t_color;

/*
**	choose_fractal.c
*/
typedef void	(*t_fract_jt)(void *environ, int pix_ind);
typedef	void	(*t_f_set_jt)(void *environ);
int				get_fract_funct(void *environ, char *choice_str);

typedef struct	s_envars
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			size;
	int			fract_choice;
	float		*iter_buf;
	size_t		iter_lim;
	double		x_t;
	double		y_t;
	pthread_t	tids[4];
	int			color_style;
	int			psychedelic;
	int			ccolor;
	t_fractal	f;
	t_color		c;
	t_fract_jt	fract_func;
	t_f_set_jt	fract_setup;
	t_image		image;
	t_mouse		mouse;
}				t_envars;

typedef struct	s_targs
{
	t_envars	*env;
	int			quad;
}				t_targs;

/*
**	main.c
*/
void			start_hooks(t_envars *env);
void			setup_env(t_envars *env);

/*
**	fractal_utils.c
*/
void			setup_fract(t_envars *env);
int				idx(int row, int col, int dim);
double			ft_lint(double start, double end, double decimal_percent);
t_dcmplx		abs_sqr(t_dcmplx z);
t_fractal		calc_fract_min_max(t_envars *env, t_fractal f);

/*
**	image.c
*/
void			init_img(t_envars *env);
void			img_pixel_put(t_envars *env, double x, double y, int color);
void			clear_img(t_envars *env);

/*
**	render.c
*/
void			render(t_envars *env);

/*
**	fractal_escape_time.c
*/
float			escape_time(t_envars *env, t_fractal f);

/*
**	fractal_setup_0.c
*/
void			setup_mandelbrot(void *environ);
void			setup_julia(void *environ);
void			setup_bship(void *environ);
void			setup_trijulia(void *environ);
void			setup_tribrot(void *environ);

/*
**	fractal_setup_1.c
*/
void			setup_excalibur(void *environ);
void			setup_quadjulia(void *environ);
void			setup_quadrobrot(void *environ);
void			setup_quadroship(void *environ);

/*
**	fractal_funcs_0.c
*/
void			julia(void *environ, int pix_ind);
void			mandelbrot(void *environ, int pix_ind);

/*
**	color.c
*/
void			setup_color(t_envars *env);
void			toggle_palette(t_envars *env);
void			color_surprise(t_envars *env);
void			psychedelic_surprise(t_envars *env);
int				choose_col(t_envars *env, float iter);

/*
**	key_hooks.c
*/
int				keydown_hook(int key, t_envars *env);
int				key_pressed_hook(int key, t_envars *env);

/*
**	mouse_hooks.c
*/
void			init_mouse(t_envars *env);
int				mouse_pressed_hook(int button, int x, int y, t_envars *env);
int				mouse_released_hook(int button, int x, int y, t_envars *env);
int				mouse_moved_hook(int x, int y, t_envars *env);

/*
**	loop_hooks.c
*/
int				loop_hook(t_envars *env);
#endif
