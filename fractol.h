/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:23 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:13:29 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "structures.h"
# include "mlx_keys.h"

# define HEIGHT 1000
# define WIDTH 1000

/*
Fern fractal
*/
void		init_fern_fractal(t_f *fern);
void		fern_fractal(t_f *fern);
void		fern_create_random_pixels(t_f *f);
/*
Color && images
*/
int			initialize_color(t_f *f);
t_image		*initialize_image(t_f *fern);
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_f *fern, int x, int y, int color);
int			render_next_frame(t_f *fern);
int			colors_random(t_f *fern);
void		add_help_menu(t_f *f);
void		add_starting_menu(t_f *f);
void		shift_color(t_f *f);
void		add_fractal_menu(t_f *f);
void		black_and_white_addition(t_f *f, int t);
/*
Julia && Mandelbrot
*/
void		initialize_limits(t_f *f);
void		mandelbrot(t_f *f);
void		julia(t_f *f);
t_complex	initialize_complex(double re, double im);
void		draw_fractal(t_f *f);
int			change_julia(int x, int y, t_f *f);
double		interpolate(double start, double end, double interpolation);
/*
Control
*/
int			key_control(int key, t_f *f);
int			mouse_control(int key, int x, int y, t_f *f);
void		key_control_for_fern(t_f *f, int key);
void		moving(int key, t_f *f);
void		key_control_fractal_change(t_f *f, int key);

#endif