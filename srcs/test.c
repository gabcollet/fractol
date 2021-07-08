/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:26:28 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/08 18:46:18 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	deal_key(int key, void *param)
{
	param = 0;
	if (key == 0x35)
		exit(0);
	if (key == 0x07)
		exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int 	offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

void	make_square(int x, int y, t_data data, int color)
{
	// x et y sont les coordonées du coin supérieur gauche.
	int	length;
	int tempx;
	int tempy;
	
	tempx = x;
	tempy = y;
	length = 500; //indique la longueur du carré
	while (x <= tempx +	length)
	{
		if (x == tempx || x == tempx + length)
		{
			while (y < tempy + length)
			{
				my_mlx_pixel_put(&data, x, y, color);
				y++;
			}
			if (x == 100 && y == tempy + length)
			{
				while (x < tempx + length)
				{
					my_mlx_pixel_put(&data, x, y, color);
					x++;
				}
				x = tempx;
			}
			y = tempy;
		}
		my_mlx_pixel_put(&data, x, y, color);
		x++;
	}
}

void	make_circle(int h, int k, t_data data, int color)
{
	//h et k sont les coordonée du centre du cercle
	int theta = 0; //angle de chaque loop
	int x; 
	int y;
	int step = 1; //nombre à ajouter à theta chaque loop (degrée)
	int r = 200; //rayon du cercle

	while (theta <= 360)
	{
		x = h + r * cos(theta);
		y = k + r * sin(theta);
		my_mlx_pixel_put(&data, x, y, color);
		theta += step;
	}
}

void	make_triangle(int x, int y, t_data data, int color)
{
	//x et y sont le sommet du triangle equilateral
	int height;
	int hypo;
	int tempx;
	int tempy;
	int step; //plus le chiffre est grand plus le triangle est serré

	tempx = x;
	tempy = y;
	step = 10;
	height = 20; //hauteur du triangle
	hypo = height / sin(60);
	while ((x <= tempx + (hypo / 2)) && (y >= tempy - height))
	{
		x += (hypo / 2) / step;
		y -= hypo / step;
		my_mlx_pixel_put(&data, x, y, color);
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 800, "Hello 42");
	img.img = mlx_new_image(mlx, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	make_square(100, 100, img, 0x0000FF00);
	make_circle(500, 500, img, 0x00FF0000);
	make_triangle(100, 100, img, 0x0000FF00);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_hook(win, 2, 1L << 0, deal_key, (void *)0);
	mlx_loop(mlx);
}
