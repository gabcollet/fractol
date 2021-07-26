/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:02:53 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/26 14:53:50 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

# define WIDTH 1200
# define HEIGHT	800

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_type
{
	int		type;		//va servir a determiner le fractal
	int		depth;		
	int		iteration;
	double	width;
	double	height;
	double	scale;		//aucune idée a quoi ca sert
	double	xr;
	double	yi;
}				t_type;

typedef struct	s_mouse  //pas encore utilisé
{
	int		state;
	int		pos_x;
	int		pos_y;
}				t_mouse;

typedef struct	s_mlx
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	int		color;
}				t_mlx;

typedef struct	s_fractol
{
	t_mlx	mlx;
	t_color	color;
	t_type	fractal;
	t_mouse	mouse;
}				t_fractol;

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int 	rainbow(t_fractol *fractol);
int		julia(t_fractol *fractol);
int		mandelbrot(t_fractol *fractol);
void	random_colors(t_fractol *fractol);
int		key(int key, t_fractol *fractol);
void	put_pixel(t_fractol *fractol, int depth);
int		ft_draw(t_fractol *fractol);

#endif
