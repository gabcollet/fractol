/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:26:28 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/12 19:23:35 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_test.h"

int	close(int key)
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

int	render_next_frame(void *rgb)
{
	rgbchange(rgb);
	return (0);
}

int	main(void)
{
	t_data	img;

	img.r = 0;
	img.g = 255;
	img.b = 255;
	img.len = 2600;
	img.height = 1325;
	
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 2600, 1325, "Hello 42");
	img.img = mlx_new_image(img.mlx, 2600, 1325);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	/* make_square(100, 100, img, 16777095);
	make_circle(500, 500, img, 0x00FF0000);
	make_triangle(200, 200, 200, img, 0x0000FF00); */
	/* mlx_put_image_to_window(mlx, win, img.img, 0, 0); */
	/* mlx_key_hook(img.win, ft_mactoc, (void *)0); */
	mlx_hook(img.win, 2, 0L, close, (void *)0);
	mlx_loop_hook(img.mlx, make_rainbow, &img);
	/* mlx_loop(img.mlx); */
}
