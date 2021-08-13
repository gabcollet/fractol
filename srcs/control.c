/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:30 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/13 14:07:32 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* Function that assigns the keys of the keyboard */
int	key(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit(0);
	else if (key == SPACE_KEY)
		random_colors(fractol);
	else if (key == W_KEY || key == UP_ARROW)
		fractol->fractal.yi -= 10 / fractol->fractal.scale;
	else if (key == A_KEY || key == LEFT_ARROW)
		fractol->fractal.xr -= 10 / fractol->fractal.scale;
	else if (key == S_KEY || key == DOWN_ARROW)
		fractol->fractal.yi += 10 / fractol->fractal.scale;
	else if (key == D_KEY || key == RIGHT_ARROW)
		fractol->fractal.xr += 10 / fractol->fractal.scale;
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	ft_draw(fractol);
	return (0);
}

/* Function that zooms in by increasing the scale, the iteration and adding
 to the x and y the values of scale_multi */
void	zoom_in(int x, int y, t_fractol *f)
{
	double	scale_multi;

	if (f->fractal.scale >= SCALE_LIMIT)
		return ;
	else
	{
		scale_multi = f->fractal.scale * SCALE_PRS;
		f->fractal.xr = ((double)x / f->fractal.scale + f->fractal.xr) \
		 - (scale_multi / 2);
		f->fractal.xr += (scale_multi / 2) - ((double)x / scale_multi);
		f->fractal.yi = ((double)y / f->fractal.scale + f->fractal.yi) \
		 - (scale_multi / 2);
		f->fractal.yi += (scale_multi / 2) - ((double)y / scale_multi);
		f->fractal.scale *= SCALE_PRS;
		f->fractal.iteration += SCALE_ITER;
	}
}

/* Same but in the other way */
void	zoom_out(int x, int y, t_fractol *f)
{
	double	scale_multi;

	scale_multi = f->fractal.scale / SCALE_PRS;
	f->fractal.xr = ((double)x / f->fractal.scale + f->fractal.xr) \
	 - (scale_multi / 2);
	f->fractal.xr += (scale_multi / 2) - ((double)x / scale_multi);
	f->fractal.yi = ((double)y / f->fractal.scale + f->fractal.yi) \
	 - (scale_multi / 2);
	f->fractal.yi += (scale_multi / 2) - ((double)y / scale_multi);
	f->fractal.scale /= SCALE_PRS;
	f->fractal.iteration -= SCALE_ITER;
}

/* Function which takes the inputs of the mouse */
int	mouse(int mouse, int x, int y, t_fractol *fractol)
{
	if (mouse == DOWN_SCROLL)
		zoom_in(x, y, fractol);
	if (mouse == UP_SCROLL)
		zoom_out(x, y, fractol);
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
	ft_draw(fractol);
	return (0);
}
