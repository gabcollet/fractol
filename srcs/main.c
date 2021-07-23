/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:50:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/23 19:10:02 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		julia(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = -0.8;
	ci = 0.156;
	zi = (fractol->fractal.yi - HEIGHT / 2) / (HEIGHT / 2);
	zr = (fractol->fractal.xr - WIDTH / 2) / (WIDTH / 2);
	while ((zr * zr) + (zi * zi) < 4
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	/* printf("%d\n", fractol->fractal.depth); */
	return (fractol->fractal.depth);
}

int		mandelbrot(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zi = 0;
	zr = 0;
	while ((zr * zr) + (zi * zi) < 4
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + (fractol->fractal.xr - WIDTH / 2) / (WIDTH / 2) - 0.5;
		zi = (2 * zi) * tmp_zr + (fractol->fractal.yi - HEIGHT / 2) / (HEIGHT / 2);
		fractol->fractal.depth += 1;
	}
	/* printf("%d\n", fractol->fractal.depth); */
	return (fractol->fractal.depth);
}

void rainbow2(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

unsigned int rainbow(t_fractol *fractol)
{
	int percent;
	int depth = fractol->fractal.depth;
	percent = fractol->fractal.iteration / 6;
	
	if (depth < percent)
	{
		rainbow2((depth/percent) * 256, 0, 255, &fractol->color);
		if (fractol->color.r == 0)
			return 0;
	}
	else if (depth > (percent) && depth < (percent) * 2)
		rainbow2(255, (depth/percent - 1) * 256, 255, &fractol->color);
	else if (depth > percent * 2 && depth < percent * 3)
		rainbow2(255, (depth/percent - 2) * 256, 0, &fractol->color);
	else if (depth > percent * 3 && depth < percent * 4)
		rainbow2(255, 255, (depth/percent - 3) * 256, &fractol->color);
	else if (depth > percent * 4 && depth < percent * 5)
		rainbow2(0, 255, (depth/percent - 4) * 256, &fractol->color);
	else if (depth > percent * 5)
		rainbow2((depth/percent - 5) * 256, 255, 255, &fractol->color);
	return (fractol->color.r + (fractol->color.g * 256) + (fractol->color.b * 65536));
}

void ft_loop(t_fractol *fractol)
{
	int x;
	int y;
	int color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractol->fractal.yi = y;
			fractol->fractal.xr = x;
			julia(fractol);
			/* mandelbrot(fractol); */
			color = rainbow(fractol);
			my_mlx_pixel_put(&fractol->mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
}

int		main()
{
	t_fractol	f;
	
	f.fractal.iteration = 500; 
	f.fractal.scale = 1;
	f.fractal.width = WIDTH;
	f.fractal.height = HEIGHT;
	
	f.mlx.mlx = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "Fractol");
	f.mlx.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
	f.mlx.addr = mlx_get_data_addr(f.mlx.img, &f.mlx.bits_per_pixel,
			&f.mlx.line_length, &f.mlx.endian);
	ft_loop(&f);
	mlx_key_hook(f.mlx.win, close, (void *)0);
	/* mlx_loop_hook(img.mlx, function, &struct qui contient les vars); */
	mlx_loop(f.mlx.mlx);
	return (0);
}
