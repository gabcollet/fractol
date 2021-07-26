/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rainbow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:35:19 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/23 17:34:09 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int rgbchange(t_color *rgb)
{
	int multi;

	multi = 15; //chiffre impaire seulement
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

/* int make_rainbow(t_data *data)
{
	int tempy;
	int	i;
	int color;

	data->x = 0;
	data->y = 0;
	i = 0;
	tempy = data->y;
	color = rgbchange(data);
	while (i < data->len)
	{
		while (data->y < tempy + data->height)
		{
			data->y++;
			my_mlx_pixel_put(data, data->x, data->y, color);
		}
		data->x++;
		i++;
		data->y = tempy;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
} */
