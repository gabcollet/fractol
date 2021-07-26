/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:52:24 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/26 11:53:05 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	return (fractol->fractal.depth);
}
