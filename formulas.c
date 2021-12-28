/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:18 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:19 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_f *f)
{
	t_complex	z;

	z = initialize_complex(f->c.re, f->c.im);
	f->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && f->iter < f->max_iter)
	{
		z = initialize_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ f->c.re, 2.0 * z.re * z.im + f->c.im);
		f->iter++;
	}
}

void	julia(t_f *f)
{
	t_complex	z;

	z = initialize_complex(f->c.re, f->c.im);
	f->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && f->iter < f->max_iter)
	{
		z = initialize_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ f->k.re, 2.0 * z.re * z.im + f->k.im);
		f->iter++;
	}
}
