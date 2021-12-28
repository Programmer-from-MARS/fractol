/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:25 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:26 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*initialize_image(t_f *f)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		exit (1);
	image->image = mlx_new_image(f->mlx_ptr, WIDTH + 500, HEIGHT);
	image->data_addr = mlx_get_data_addr(image->image,
			&(image->pixel_bits), &(image->line_bytes),
			&(image->endian));
	return (image);
}

void	initialize_limits(t_f *f)
{
	f->max_iter = 50;
	f->min.re = -2.0;
	f->max.re = 2.0;
	f->min.im = -2.0;
	f->max.im = f->min.im + (f->max.re - f->min.re) * HEIGHT / WIDTH;
	f->k = initialize_complex(-0.4, 0.6);
	f->press = 0;
	f->shift = 1;
}

t_complex	initialize_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
