/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:09:55 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/09 17:37:53 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdlib.h>
#include <math.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

void	make_square(int x, int y, t_data data, int color);
void	make_circle(int h, int k, t_data data, int color);
void	make_triangle(double x, double y, double height, t_data data, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void make_rainbow(t_data data, int x, int y, int len, int height);

#endif