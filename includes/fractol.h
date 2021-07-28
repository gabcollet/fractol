/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:02:53 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/28 17:39:48 by gcollet          ###   ########.fr       */
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

# define WIDTH 			1200
# define HEIGHT			800
# define SCALE_LIMIT	50000000
# define SCALE_PRS		1.3
# define SCALE_ITER		3

# define ESC 			53
# define SPACE_KEY 		49
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

# define UP_ARROW		126
# define LEFT_ARROW		123
# define DOWN_ARROW		125
# define RIGHT_ARROW	124

# define UP_SCROLL		0x04
# define DOWN_SCROLL	0x05

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_type
{
	int		type;
	int		depth;
	int		iteration;
	double	width;
	double	height;
	double	scale;
	double	xr;
	double	yi;
	double  cr;
	double	ci;
}				t_type;

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
}				t_fractol;

int		main(int argc, char **argv);
void	menu(void);
void	ft_init(t_fractol *fractol, char **av);
void	fractal_choice(t_fractol *fractol, char **av);

int		julia(t_fractol *fractol);
int		mandelbrot(t_fractol *fractol);
int		rabbit(t_fractol *fractol);
int		monster(t_fractol *fractol);

void	random_colors(t_fractol *fractol);
void	put_pixel(t_fractol *fractol, int depth);
void	ft_string(char * str1, int val, t_fractol *f, int x, int y);
int		ft_draw(t_fractol *fractol);

int		key(int key, t_fractol *fractol);
void	zoom_in(int x, int y, t_fractol *f);
void	zoom_out(int x, int y, t_fractol *f);
int 	mouse(int mouse, int x, int y, t_fractol *fractol);

#endif
