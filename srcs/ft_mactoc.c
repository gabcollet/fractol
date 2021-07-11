/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mactoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:41:59 by gcollet           #+#    #+#             */
/*   Updated: 2021/07/11 11:04:59 by gcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mactoc(int key)
{
	if (key == 0)
		printf("%c", 'a');
	else if (key == 11)
		printf("%c", 'b');
	else if (key == 11)
		printf("%c", 'b');
	else if (key == 8)
		printf("%c", 'c');
	else if (key == 2)
		printf("%c", 'd');
	else if (key == 14)
		printf("%c", 'e');
	else if (key == 3)
		printf("%c", 'f');
	else if (key == 5)
		printf("%c", 'g');
	else if (key == 4)
		printf("%c", 'h');
	else if (key == 34)
		printf("%c", 'i');
	else if (key == 38)
		printf("%c", 'j');
	else if (key == 40)
		printf("%c", 'k');
	else if (key == 37)
		printf("%c", 'l');
	else if (key == 46)
		printf("%c", 'm');
	else if (key == 45)
		printf("%c", 'n');
	else if (key == 31)
		printf("%c", 'o');
	else if (key == 35)
		printf("%c", 'p');
	else if (key == 12)
		printf("%c", 'q');
	else if (key == 15)
		printf("%c", 'r');
	else if (key == 1)
		printf("%c", 's');
	else if (key == 17)
		printf("%c", 't');
	else if (key == 32)
		printf("%c", 'u');
	else if (key == 9)
		printf("%c", 'v');
	else if (key == 13)
		printf("%c", 'w');
	else if (key == 7)
		printf("%c", 'x');
	else if (key == 16)
		printf("%c", 'y');
	else if (key == 6)
		printf("%c", 'z');
	else if (key == 49)
		printf("%c", ' ');
	else if (key == 36)
		printf("%c", '\n');
	else
		printf("%d", key);
	return (0);
}