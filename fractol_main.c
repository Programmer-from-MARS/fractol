/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:20 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:21 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_drawing(t_f *f)
{
	f->flag = 0;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH + 500, HEIGHT, "Fractol");
	f->image = initialize_image(f);
	mlx_hook(f->win_ptr, 2, 0, key_control, f);
	mlx_hook(f->win_ptr, 4, 0, mouse_control, f);
	mlx_loop_hook(f->mlx_ptr, render_next_frame, f);
	mlx_loop(f->mlx_ptr);
}

int	main(void)
{
	t_f	f;

	start_drawing(&f);
	return (0);
}
