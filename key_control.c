/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:27 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:28 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_control(int key, t_f *f)
{
	if (key == ESC)
		exit (1);
	key_control_fractal_change(f, key);
	key_control_for_fern(f, key);
	if (key == PLUS)
	{
		if (f->max_iter < 50)
			f->max_iter += 1;
		else if (f->max_iter < 1000000000)
			f->max_iter *= 1.05;
	}
	if (key == MINUS)
	{
		if (f->max_iter > 50)
			f->max_iter *= 0.95;
		else if (f->max_iter > 1)
			f->max_iter -= 1;
	}
	if (key == R)
		initialize_limits(f);
	if (key == DOWN || key == RIGHT || key == LEFT || key == UP)
		moving(key, f);
	if (key == C)
		shift_color(f);
	return (0);
}

void	key_control_for_fern(t_f *f, int key)
{
	if (key == K1 && f->r < 255)
		f->color = create_trgb(0, ++f->r, f->g, f->b);
	if (key == K2 && f->g < 255)
		f->color = create_trgb(0, f->r, ++f->g, f->b);
	if (key == K3 && f->b < 255)
		f->color = create_trgb(0, f->r, f->g, ++f->b);
	if (key == K4 && f->r > 0)
		f->color = create_trgb(0, --f->r, f->g, f->b);
	if (key == K5 && f->g > 0)
		f->color = create_trgb(0, f->r, --f->g, f->b);
	if (key == K6 && f->b > 0)
		f->color = create_trgb(0, f->r, f->g, --f->b);
	if (key == K7)
		f->color = colors_random(f);
	if (key == K8 && f->iter < 10000000)
		f->iter += 2500;
	if (key == K9 && f->iter > 2500)
		f->iter -= 2500;
}

void	key_control_fractal_change(t_f *f, int key)
{
	if (key == F)
	{
		init_fern_fractal(f);
		f->flag = 1;
	}
	if (key == J)
	{
		f->formula = &julia;
		initialize_limits(f);
		f->flag = 3;
	}
	if (key == M)
	{
		f->formula = &mandelbrot;
		initialize_limits(f);
		f->flag = 2;
	}
}

void	moving(int key, t_f *f)
{
	t_complex	delta;

	delta = initialize_complex((f->max.re - f->min.re) * 0.05,
			(f->max.im - f->min.im) * 0.05);
	if (key == RIGHT)
	{
		f->min.re = f->min.re - delta.re;
		f->max.re = f->max.re - delta.re;
	}
	else if (key == LEFT)
	{
		f->min.re = f->min.re + delta.re;
		f->max.re = f->max.re + delta.re;
	}
	else if (key == UP)
	{
		f->min.im = f->min.im - delta.im;
		f->max.im = f->max.im - delta.im;
	}
	else if (key == DOWN)
	{
		f->min.im = f->min.im + delta.im;
		f->max.im = f->max.im + delta.im;
	}
}

void	shift_color(t_f *f)
{
	f->shift++;
	if (f->shift > 4)
		f->shift = 1;
}
