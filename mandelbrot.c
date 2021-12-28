/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:30 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:31 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_f *f)
{
	int			x;
	int			y;
	t_complex	factor;

	factor = initialize_complex((f->max.re - f->min.re) / (WIDTH),
			(f->max.im - f->min.im) / (HEIGHT));
	y = 0;
	while (y < HEIGHT)
	{
		f->c.im = f->max.im - y * factor.im;
		x = 0;
		while (x < WIDTH)
		{
			f->c.re = f->min.re + x * factor.re;
			f->formula(f);
			my_mlx_pixel_put(f, x, y, initialize_color(f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image->image, 0, 0);
	add_fractal_menu(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->menu, WIDTH, 0);
}
