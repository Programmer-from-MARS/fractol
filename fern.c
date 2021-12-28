/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:16 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:17 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fern_fractal(t_f *f)
{
	f->x0 = 0;
	f->y0 = 0;
	f->x1 = 0;
	f->y1 = 0;
	f->iter = 10000;
	f->r = 0;
	f->g = 0;
	f->b = 0;
	f->color = create_trgb(0, 0, 0, 0);
}

void	fern_fractal(t_f *f)
{
	int	iter;

	iter = f->iter;
	while (iter > 0)
	{
		fern_create_random_pixels(f);
		my_mlx_pixel_put(f,
			180 * f->x1 + WIDTH / 2.4,
			HEIGHT - 100 * f->y1,
			f->color);
		f->x0 = f->x1;
		f->y0 = f->y1;
		iter--;
	}
}

void	fern_create_random_pixels(t_f *f)
{
	f->random = rand() % 100;
	if (f->random == 0)
	{
		f->x1 = 0;
		f->y1 = 0.16 * f->y0;
	}
	else if (f->random >= 1 && f->random <= 7)
	{
		f->x1 = -0.15 * f->x0 + 0.28 * f->y0;
		f->y1 = 0.26 * f->x0 + 0.24 * f->y0 + 0.44;
	}
	else if (f->random >= 8 && f->random <= 15)
	{
		f->x1 = 0.2 * f->x0 - 0.26 * f->y0;
		f->y1 = 0.23 * f->x0 + 0.22 * f->y0 + 1.6;
	}
	else
	{
		f->x1 = 0.85 * f->x0 + 0.04 * f->y0;
		f->y1 = -0.04 * f->x0 + 0.85 * f->y0 + 1.6;
	}
}
