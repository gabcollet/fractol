/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:03:34 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/09 12:04:10 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	make_circle(int h, int k, t_data data, int color)
{
	//h et k sont les coordonée du centre du cercle
	int theta = 0; //angle de chaque loop
	int x; 
	int y;
	int step = 1; //nombre à ajouter à theta chaque loop (degrée)
	int r = 200; //rayon du cercle

	while (theta <= 360)
	{
		x = h + r * cos(theta);
		y = k + r * sin(theta);
		my_mlx_pixel_put(&data, x, y, color);
		theta += step;
	}
}
