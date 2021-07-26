/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:05:11 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/09 12:12:48 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	make_triangle(double x, double y, double height, t_data data, int color)
{
	//x et y sont le sommet du triangle equilateral
	//height est la hauteur du triangle
	double hypo;
	double tempx;
	double tempy;
	int temp;
	
	tempx = x;
	tempy = y;
	
	hypo = (height / (sin(60 * (M_PI / 180))));
	while ((x <= tempx + (hypo / 2)) && (y <= tempy + height))
	{
		x += (hypo / 2) / height;
		y += hypo / height;
		my_mlx_pixel_put(&data, x, y, color);
	}
	temp = x;
	x = tempx;
	y = tempy;
	while ((x >= tempx - (hypo / 2)) && (y <= tempy + height))
	{
		x -= (hypo / 2) / height;
		y += hypo / height;
		my_mlx_pixel_put(&data, x, y, color);
	}
	while (x < temp)
	{
		x += hypo / height;
		my_mlx_pixel_put(&data, x, y, color);
	}
}
