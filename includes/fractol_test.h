/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:09:55 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/12 11:46:46 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TEST_H
# define FRACTOL_TEST_H

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int r;
	int g;
	int b;
	int x;
	int y;
	int len;
	int height;
	void	*mlx;
	void	*win;
}				t_data;

void	make_square(int x, int y, t_data data, int color);
void	make_circle(int h, int k, t_data data, int color);
void	make_triangle(double x, double y, double height, t_data data, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	make_rainbow(t_data *data);
int		ft_mactoc(int key);
unsigned int rgbchange(t_data *rgb);

#endif
