/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:24:20 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/31 13:11:35 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

int		mouse_win1(int x, int y, t_map *data)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && data->mst == 1)
	{
		data->creal = ((double)x - WIN_W * 2) / 1000;
		data->cimag = (WIN_H - (double)y) / 1000;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
		frselren(data);
	}
	return (0);
}

int		mouse_win2(int button, int x, int y, t_map *data)
{
	data->msposx = x;
	data->msposy = y;
	if (button == 4 || button == 5)
	{
		data->zoom *= button == 4 ? 1 + 0.05 : 0.95;
		data->maxiter += button = 4 ? 5 : 0;
	}
	if (button == 2 && data->fsel == 1)
		data->mst += data->mst > 1 ? -1 : 1;
	if (button == 1)
		data->color += data->color < 5000 ? 265 : -4770;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	frselren(data);
	return (0);
}

int		keyboard(int key, t_map *data)
{
	if (key == 18)
		initalljulia(data);
	if (key == 19)
		initallmandelbrot(data);
	if (key == 20)
		initallburningships(data);
	if (key == 125 || key == 126)
		data->movey += key == 126 ? -0.05 / data->zoom : 0.05 / data->zoom;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 24 || key == 27)
	{
		data->zoom *= key == 24 ? 1.5 + 0.05 : 0.75;
		data->maxiter += key == 24 ? 5 : 0;
	}
	if (key == 123 || key == 124)
		data->movex += key == 124 ? 0.05 / data->zoom : -0.05 / data->zoom;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	frselren(data);
	return (0);
}
