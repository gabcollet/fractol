/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:11:58 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/27 18:59:24 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		random_colors(t_fractol *fractol)
{
	fractol->color.r += 15;
	fractol->color.g += 41;
	fractol->color.b += 10;
}

void		put_pixel(t_fractol *fractol, int depth)
{
	int			pos;

	pos = (fractol->fractal.height + (fractol->fractal.width * WIDTH)) * 4;
	if (fractol->fractal.height < WIDTH \
			&& fractol->fractal.width < HEIGHT \
				&& depth == fractol->fractal.iteration)
	{
		fractol->mlx.addr[pos] = 0x00;
		fractol->mlx.addr[pos + 1] = 0x00;
		fractol->mlx.addr[pos + 2] = 0x00;
	}
	else if (fractol->fractal.height < WIDTH \
				&& fractol->fractal.width < HEIGHT)
	{
		fractol->mlx.addr[pos] = fractol->color.r + (depth * 2.42);
		fractol->mlx.addr[pos + 1] = fractol->color.g + (depth * 3.52);
		fractol->mlx.addr[pos + 2] = fractol->color.b + (depth * 4.65);
	}
}

int ft_draw(t_fractol *fractol)
{
	int depth;
	double		tmp_width;
	
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	/* random_colors(fractol); */
	tmp_width = fractol->fractal.width;
	while (fractol->fractal.height < WIDTH)
	{
		fractol->fractal.width = tmp_width;
		while (fractol->fractal.width < WIDTH)
		{
			depth = julia(fractol);
			/* depth = mandelbrot(fractol); */
			put_pixel(fractol, depth);
			fractol->fractal.width += 1;
		}
		fractol->fractal.height += 1;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, 10, 5, 0xFFFFFF, ft_strjoin("Number of iterations : ", ft_itoa(fractol->fractal.iteration)));
	mlx_string_put(fractol->mlx.mlx, fractol->mlx.win, 10, 35, 0xFFFFFF, ft_strjoin("Zoom level: ", ft_itoa((int)fractol->fractal.scale)));
	//faire strjoin et itoa a coté pour pouvoir free par la suite

	return (0);
}
