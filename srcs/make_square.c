/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:58:52 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/09 11:59:39 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	make_square(int x, int y, t_data data, int color)
{
	// x et y sont les coordonées du coin supérieur gauche.
	int	length;
	int tempx;
	int tempy;
	
	tempx = x;
	tempy = y;
	length = 500; //indique la longueur du carré
	while (x <= tempx +	length)
	{
		if (x == tempx || x == tempx + length)
		{
			while (y < tempy + length)
			{
				my_mlx_pixel_put(&data, x, y, color);
				y++;
			}
			if (x == 100 && y == tempy + length)
			{
				while (x < tempx + length)
				{
					my_mlx_pixel_put(&data, x, y, color);
					x++;
				}
				x = tempx;
			}
			y = tempy;
		}
		my_mlx_pixel_put(&data, x, y, color);
		x++;
	}
}
