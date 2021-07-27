/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:47:33 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/26 14:35:31 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void rgb(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

int rainbow(t_fractol *fractol)
{
	int percent;
	int depth = fractol->fractal.depth;
	percent = fractol->fractal.iteration / 6;
	
	if (depth < percent)
	{
		rgb((depth/percent) * 256, 0, 255, &fractol->color);
		if (fractol->color.r == 0)
			return 0;
	}
	else if (depth > (percent) && depth < (percent) * 2)
		rgb(255, (depth/percent - 1) * 256, 255, &fractol->color);
	else if (depth > percent * 2 && depth < percent * 3)
		rgb(255, (depth/percent - 2) * 256, 0, &fractol->color);
	else if (depth > percent * 3 && depth < percent * 4)
		rgb(255, 255, (depth/percent - 3) * 256, &fractol->color);
	else if (depth > percent * 4 && depth < percent * 5)
		rgb(0, 255, (depth/percent - 4) * 256, &fractol->color);
	else if (depth > percent * 5)
		rgb((depth/percent - 5) * 256, 255, 255, &fractol->color);
	return (fractol->color.r + (fractol->color.g * 256) + (fractol->color.b * 65536));
}
