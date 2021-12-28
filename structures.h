/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanastas <eanastas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:09:00 by eanastas          #+#    #+#             */
/*   Updated: 2021/12/17 16:09:31 by eanastas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}				t_image;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_f
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	int			iter;
	int			random;
	int			color;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	int			m;
	int			r;
	int			g;
	int			b;
	void		*help;
	void		*start;
	void		*menu;
	int			flag;
	int			max_iter;
	int			press;
	int			shift;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	void		(*formula)(struct s_f *);
}				t_f;

#endif