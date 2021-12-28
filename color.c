/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:13 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:14 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	colors_random(t_f *f)
{
	f->r = rand() % 255;
	f->g = rand() % 255;
	f->b = rand() % 255;
	return (create_trgb(0, f->r, f->g, f->b));
}

int	initialize_color(t_f *f)
{
	double	t;

	t = (double)f->iter / f->max_iter;
	if (f->shift == 1)
	{
		f->r = (int)(9 * (1 - t) * pow(t, 3) * 255) % 255;
		f->g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) % 255;
		f->b = (int)(8.5 * pow((1 - t), 3) * t * 255) % 255;
	}
	if (f->shift == 2)
	{
		f->g = (int)(9 * (1 - t) * pow(t, 3) * 255) % 255;
		f->r = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) % 255;
		f->b = (int)(8.5 * pow((1 - t), 3) * t * 255) % 255;
	}
	if (f->shift == 3)
	{
		f->b = (int)(9 * (1 - t) * pow(t, 3) * 255) % 255;
		f->g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) % 255;
		f->r = (int)(8.5 * pow((1 - t), 3) * t * 255) % 255;
	}
	black_and_white_addition(f, t);
	return (create_trgb(0, f->g, f->g, f->b));
}

void	black_and_white_addition(t_f *f, int t)
{
	if (f->shift == 4)
	{
		if ((int)t % 2 == 0)
		{
			f->r = 0;
			f->g = 0;
			f->b = 0;
		}
		else
		{
			f->r = 255;
			f->g = 255;
			f->b = 255;
		}
	}
}
