/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:26:28 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/11 11:00:30 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	deal_key(int key)
{
	if (key == 53)
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
	make_rainbow(img, 100, 100, 800, 100);
	/* make_square(100, 100, img, 16777095);
	make_circle(500, 500, img, 0x00FF0000);
	make_triangle(200, 200, 200, img, 0x0000FF00); */
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_key_hook(win, ft_mactoc, (void *)0);
	mlx_hook(win, 2, 1L << 0, deal_key, (void *)0);
	mlx_loop(mlx);
}
