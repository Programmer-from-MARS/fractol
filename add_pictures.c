/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pictures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:08:10 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:08:11 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Add helpfull pictures on the right during rendering process
*/

void	add_help_menu(t_f *f)
{
	char	*relative_path;
	int		img_w;
	int		img_h;

	relative_path = "./pics/fern_menu.xpm";
	f->help = mlx_xpm_file_to_image(f->mlx_ptr, relative_path, &img_w, &img_h);
}

void	add_starting_menu(t_f *f)
{
	char	*relative_path;
	int		img_w;
	int		img_h;

	relative_path = "./pics/start.xpm";
	f->start = mlx_xpm_file_to_image(f->mlx_ptr, relative_path, &img_w, &img_h);
}

void	add_fractal_menu(t_f *f)
{
	char	*relative_path;
	int		img_w;
	int		img_h;

	relative_path = "./pics/menu_fractal.xpm";
	f->menu = mlx_xpm_file_to_image(f->mlx_ptr, relative_path, &img_w, &img_h);
}
