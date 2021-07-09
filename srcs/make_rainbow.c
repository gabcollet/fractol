/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rainbow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:35:19 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/09 17:38:19 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int rgbchange(t_rgb *rgb)
{
	int multi;

	multi = 3; //chiffre impaire seulement
	if (rgb->r <= 0 && rgb->g > 0 && rgb->b >= 255)
		rgb->g -= multi;
	if (rgb->r < 255 && rgb->g <= 0 && rgb->b >= 255)
		rgb->r += multi;
	if (rgb->r >= 255 && rgb->g <= 0 && rgb->b > 0)
		rgb->b -= multi;
	if (rgb->r >= 255 && rgb->g < 255 && rgb->b <= 0)
		rgb->g += multi;
	if (rgb->r > 0 && rgb->g >= 255 && rgb->b <= 0)
		rgb->r -= multi;
	if (rgb->r <= 0 && rgb->g >= 255 && rgb->b < 255)
		rgb->b += multi;
	return (rgb->b + (rgb->g * 256) + (rgb->r * 65536));
}

void make_rainbow(t_data data, int x, int y, int len, int height)
{
	int tempy;
	int	i;
	int color;
	t_rgb rgb;

	i = 0;
	tempy = y;
	rgb.r = 0;
	rgb.g = 255;
	rgb.b = 255;
	while (i < len)
	{
		color = rgbchange(&rgb);
		while (y < tempy + height)
		{
			y++;
			my_mlx_pixel_put(&data, x, y, color);
		}
		x++;
		i++;
		y = tempy;
	}
}
