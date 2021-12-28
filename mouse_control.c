/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:35 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:36 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	mouse_control(int key, int x, int y, t_f *f)
{
	t_complex	mouse;
	double		zoom;

	if (key == 1)
		f->press = !f->press;
	mouse.re = (f->min.re + x
			* ((f->max.re - f->min.re) / (WIDTH)));
	mouse.im = (f->max.im - y
			* ((f->max.im - f->min.im) / (HEIGHT)));
	if (key == 5)
		zoom = 1.20;
	else if (key == 4)
		zoom = 0.80;
	else
		zoom = 1.0;
	f->min.re = interpolate(mouse.re, f->min.re, zoom);
	f->min.im = interpolate(mouse.im, f->min.im, zoom);
	f->max.re = interpolate(mouse.re, f->max.re, zoom);
	f->max.im = interpolate(mouse.im, f->max.im, zoom);
	draw_fractal(f);
	return (0);
}

int	change_julia(int x, int y, t_f *f)
{
	if (f->press == 1 && f->flag == 3)
	{
		f->k = initialize_complex(4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(f);
	}
	return (0);
}
