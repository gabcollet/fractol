/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:11:58 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/29 10:48:55 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	random_colors(t_fractol *fractol)
{
	fractol->color.r += 15;
	fractol->color.g += 41;
	fractol->color.b += 10;
}

void	put_pixel(t_fractol *fractol, int depth)
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

void	ft_string(t_fractol *f)
{
	char	*num;
	char	*str;

	num = ft_itoa(f->fractal.iteration);
	str = ft_strjoin("Number of iterations : ", num);
	mlx_string_put(f->mlx.mlx, f->mlx.win, 10, 5, 0xFFFFFF, str);
	free (num);
	free (str);
	num = ft_itoa((int)f->fractal.scale);
	str = ft_strjoin("Scale value : ", num);
	mlx_string_put(f->mlx.mlx, f->mlx.win, 10, 35, 0xFFFFFF, str);
	free (num);
	free (str);
}

int	ft_draw(t_fractol *f)
{
	int		depth;
	double	tmp_width;

	tmp_width = f->fractal.width;
	while (f->fractal.height < WIDTH)
	{
		f->fractal.width = tmp_width;
		while (f->fractal.width < WIDTH)
		{
			if (f->fractal.type == 1)
				depth = julia(f);
			else if (f->fractal.type == 2)
				depth = mandelbrot(f);
			else if (f->fractal.type == 3)
				depth = rabbit(f);
			else if (f->fractal.type == 4)
				depth = monster(f);
			put_pixel(f, depth);
			f->fractal.width += 1;
		}
		f->fractal.height += 1;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
	ft_string(f);
	return (0);
}
