/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:11:58 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/28 17:39:55 by gcollet          ###   ########.fr       */
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

void	ft_string(char * str1, int val, t_fractol *f, int x, int y)
{
	char * num;
	char * str2;
	
	num = ft_itoa(val);
	str2 = ft_strjoin(str1, num);
	mlx_string_put(f->mlx.mlx, f->mlx.win, x, y, 0xFFFFFF, str2);
	free (num);
	free (str2);
}

int ft_draw(t_fractol *fractol)
{
	int		depth;
	double	tmp_width;
	
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	tmp_width = fractol->fractal.width;
	while (fractol->fractal.height < WIDTH)
	{
		fractol->fractal.width = tmp_width;
		while (fractol->fractal.width < WIDTH)
		{
			if (fractol->fractal.type == 1)
				depth = julia(fractol);
			else if (fractol->fractal.type == 2)
				depth = mandelbrot(fractol);
			else if (fractol->fractal.type == 3)
				depth = rabbit(fractol);
			else if (fractol->fractal.type == 4)
				depth = monster(fractol);
			put_pixel(fractol, depth);
			fractol->fractal.width += 1;
		}
		fractol->fractal.height += 1;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
	ft_string("Number of iterations : ", fractol->fractal.iteration, fractol, 10, 5);
	ft_string("Scale value : ", (int)fractol->fractal.scale, fractol, 10, 35);
	return (0);
}
