/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:37 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:38 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_f *f, int x, int y, int color)
{
	char	*dst;

	dst = f->image->data_addr + (y * f->image->line_bytes + x
			* (f->image->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_f *f)
{
	if (f->flag == 0)
	{
		add_starting_menu(f);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->start, 0, 0);
	}
	else if (f->flag == 1)
	{
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		fern_fractal(f);
		add_help_menu(f);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image->image, 0, 0);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->help, WIDTH, 0);
	}
	else if (f->flag == 2 || f->flag == 3)
	{
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		if (f->flag == 3)
			mlx_hook(f->win_ptr, 6, 0, change_julia, f);
		draw_fractal(f);
	}
	return (0);
}
