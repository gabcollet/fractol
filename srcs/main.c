/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:50:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/26 17:15:35 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		random_colors(t_fractol *fractol)
{
	/* fractol->color.r = rand() % (0x4F + 0x01);
	fractol->color.g = rand() % (0x4F + 0x01);
	fractol->color.b = rand() % (0x4F + 0x01); */
	fractol->color.r += 13;
	fractol->color.g += 17;
	fractol->color.b += 42;
}

int	key(int key, t_fractol *fractol)
{
	if (key == 53)
		exit(0);
	if (key == 0)
		random_colors(fractol);
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	ft_draw(fractol);
	return (0);
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
		fractol->mlx.addr[pos + 1] = fractol->color.g + (depth * 2.42);
		fractol->mlx.addr[pos + 2] = fractol->color.b + (depth * 2.42);
	}
}

int ft_draw(t_fractol *fractol)
{
	int depth;
	double		tmp_width;
	
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	random_colors(fractol);
	tmp_width = fractol->fractal.width;
	while (fractol->fractal.height < WIDTH)
	{
		fractol->fractal.width = tmp_width;
		while (fractol->fractal.width < HEIGHT)
		{
			fractol->fractal.yi = fractol->fractal.width;
			fractol->fractal.xr = fractol->fractal.height;
			depth = julia(fractol);
			/* depth = mandelbrot(fractol); */
			/* fractol->mlx.color = rainbow(fractol);
			my_mlx_pixel_put(&fractol->mlx, fractol->fractal.height, fractol->fractal.width, fractol->mlx.color); */
			put_pixel(fractol, depth);
			fractol->fractal.width += 1;
		}
		fractol->fractal.height += 1;
	}
	mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
	return (0);
}

int		main()
{
	t_fractol	f;
	
	f.mlx.mlx = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "Fractol");
	f.mlx.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
	f.mlx.addr = mlx_get_data_addr(f.mlx.img, &f.mlx.bits_per_pixel,
			&f.mlx.line_length, &f.mlx.endian);
	
	f.fractal.iteration = 250; 
	f.fractal.scale = 200; 				//*a quoi ca sert???
	f.fractal.width = 0;
	f.fractal.height = 0;
	f.color.r = 0x42;
	f.color.g = 0x32;
	f.color.b = 0x22;
	/* ft_draw(&f); */
	mlx_loop_hook(f.mlx.mlx, ft_draw, &f);
	mlx_key_hook(f.mlx.win, key, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}
