/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:50:20 by gcollet           #+#    #+#             */
/*   Updated: 2021/08/13 14:15:28 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* Function that initiates the values of structures */
void	ft_init(t_fractol *fractol, char **av)
{
	fractol->fractal.xr = -2.0;
	fractol->fractal.yi = -1.30;
	if (fractol->fractal.type == 2)
	{
		fractol->fractal.xr = -2.5;
		fractol->fractal.yi = -1.30;
	}
	fractol->fractal.iteration = 50;
	if (av[2])
		fractol->fractal.iteration = ft_atoi(av[2]);
	fractol->fractal.cr = 0;
	fractol->fractal.ci = 0;
	if (av[3] && av[4])
	{
		fractol->fractal.cr = ft_atof(av[3]);
		fractol->fractal.ci = ft_atof(av[4]);
	}
	fractol->fractal.scale = 300.00;
	fractol->color.r = 0x42;
	fractol->color.g = 0x32;
	fractol->color.b = 0x22;
	fractol->fractal.height = 0;
	fractol->fractal.width = 0;
}

/* Menu */
void	menu(void)
{
	printf("Arg 1 : Choose a fractal # :\n");
	printf("    Julia................1\n");
	printf("    Mandelbrot...........2\n");
	printf("    Rabbit...............3\n");
	printf("    Monster..............4\n");
	printf("(Optional) :\n");
	printf("Arg 2 : Iteration from 20 to 1000\n");
	printf("(For Julia Only) :\n");
	printf("Arg 3 : Real complex number\n");
	printf("Arg 4 : Imaginary complex number\n\n");
	printf("Commands :\n");
	printf("    ESC..................Quit\n");
	printf("    Space................Change Color\n");
	printf("    Scroll up............Zoom in\n");
	printf("    Scroll down..........Zoom out\n\n");
}

/* Function that changes the type of fractal according to the chosen argument */
void	fractal_choice(t_fractol *fractol, char **av)
{
	if (av[1][0] == '1' && av[1][1] == '\0')
		fractol->fractal.type = 1;
	else if (av[1][0] == '2' && av[1][1] == '\0')
		fractol->fractal.type = 2;
	else if (av[1][0] == '3' && av[1][1] == '\0')
		fractol->fractal.type = 3;
	else if (av[1][0] == '4' && av[1][1] == '\0')
		fractol->fractal.type = 4;
	else
	{
		printf("\n\033[31mERROR : %s is not a valid argument\e[0m\n\n", av[1]);
		menu();
		exit(0);
	}
}

/* Function which generates the image of the minilibx, gives it the address
 and calls the other functions in a loop. Refer to the menu if there is an
  error. */
int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc >= 2)
	{
		fractal_choice(&f, argv);
		f.mlx.mlx = mlx_init();
		f.mlx.win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "Fractol");
		f.mlx.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
		f.mlx.addr = mlx_get_data_addr(f.mlx.img, &f.mlx.bits_per_pixel,
				&f.mlx.line_length, &f.mlx.endian);
		ft_init(&f, argv);
		ft_draw(&f);
		mlx_key_hook(f.mlx.win, key, &f);
		mlx_mouse_hook(f.mlx.win, mouse, &f);
		mlx_loop(f.mlx.mlx);
	}
	else
	{
		printf("\n\033[31mERROR : Missing argument\e[0m\n\n");
		menu();
	}
	return (0);
}
