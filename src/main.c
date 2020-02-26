/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:24:34 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/30 15:23:05 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

void	tellins(void)
{
	ft_putstr("usage: ./fractal julia, mandelbrot or burningships\n");
}

void	frselren(t_map *data)
{
	if (data->fsel == 1)
		renderjulia(data);
	if (data->fsel == 2)
		rendermandelbrot(data);
	if (data->fsel == 3)
		renderburningship(data);
}

int		setfractal(char *line, t_map *data)
{
	if (!data)
		return (0);
	data->fsel = 0;
	if (ft_strequ(line, "julia"))
		initalljulia(data);
	if (ft_strequ(line, "mandelbrot"))
		initallmandelbrot(data);
	if (ft_strequ(line, "burningships"))
		initallburningships(data);
	return (data->fsel != 0 ? 1 : 0);
}

int		main(int argc, char **argv)
{
	t_map *data;

	if (argc != 2)
	{
		tellins();
		return (0);
	}
	data = (t_map*)malloc(sizeof(t_map));
	if (!(setfractal(argv[1], data)))
	{
		tellins();
		return (0);
	}
	initmlx(data);
	frselren(data);
	mlx_key_hook(data->fracwin, keyboard, data);
	mlx_hook(data->fracwin, 6, 3, mouse_win1, data);
	mlx_mouse_hook(data->fracwin, mouse_win2, data);
	mlx_loop(data->mlx);
}
