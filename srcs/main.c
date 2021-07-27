/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:50:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/27 18:59:33 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"



int	key(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit(0);
	if (key == A_KEY)
		random_colors(fractol);
	ft_draw(fractol);
	return (0);
}

/* x and y are the postition of the mouse  */
static void		zoom_in(int x, int y, t_fractol *f)
{
	double scale_multi;
	
	scale_multi = f->fractal.scale * SCALE_PRS;
	f->fractal.xr = ((double)x / f->fractal.scale + f->fractal.xr) - (scale_multi / 2);
	f->fractal.xr += (scale_multi / 2) - ((double)x / scale_multi);
	f->fractal.yi = ((double)y / f->fractal.scale + f->fractal.yi) - (scale_multi / 2);
	f->fractal.yi += (scale_multi / 2) - ((double)y / scale_multi);
	f->fractal.scale *= SCALE_PRS;
	f->fractal.iteration += SCALE_ITER;
}

int mouse(int mouse, int x, int y, t_fractol *fractol)
{
	if (mouse == DOWN_SCROLL)
		zoom_in(x, y, fractol);
	ft_draw(fractol);
	return (0);
}

void	ft_init(t_fractol *fractol)
{
	//changer les valleurs x et y pour le mandelbrot
	fractol->fractal.xr = -2.0;
	fractol->fractal.yi = -1.30;
	fractol->fractal.iteration = 150;
	fractol->fractal.scale = 300.00;
	fractol->color.r = 0x42;
	fractol->color.g = 0x32;
	fractol->color.b = 0x22;
}

int	main()
{
	t_fractol	f;
	
	f.mlx.mlx = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "Fractol");
	f.mlx.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
	f.mlx.addr = mlx_get_data_addr(f.mlx.img, &f.mlx.bits_per_pixel,
			&f.mlx.line_length, &f.mlx.endian);
	ft_init(&f);
	ft_draw(&f);
	/* mlx_loop_hook(f.mlx.mlx, ft_draw, &f); */
	mlx_key_hook(f.mlx.win, key, &f);
	mlx_mouse_hook(f.mlx.win, mouse, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}
