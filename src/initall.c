/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:23:32 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/31 12:59:13 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

void	initmlx(t_map *data)
{
	data->space = 0;
	data->mlx = mlx_init();
	data->fracwin = mlx_new_window(data->mlx, WIN_W, WIN_H, "fractol");
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->addrdat = (int*)mlx_get_data_addr(data->img,
			&data->bpp, &data->linesize, &data->endian);
}

void	initalljulia(t_map *data)
{
	data->maxiter = 50;
	data->zoom = 1;
	data->movex = 0;
	data->movey = 0;
	data->cimag = 0.267000;
	data->creal = -1.076;
	data->corec = 0;
	data->color = 265;
	data->mst = 1;
	data->fsel = 1;
}

void	initallmandelbrot(t_map *data)
{
	data->maxiter = 50;
	data->zoom = 1;
	data->movex = -1;
	data->movey = 0;
	data->cimag = 0;
	data->creal = 0;
	data->corec = 0;
	data->color = 265;
	data->mst = 0;
	data->fsel = 2;
}

void	initallburningships(t_map *data)
{
	data->maxiter = 50;
	data->zoom = 0.75;
	data->movex = -0.5;
	data->movey = -0.6;
	data->cimag = 0;
	data->creal = 0;
	data->corec = 0;
	data->color = 265;
	data->mst = 0;
	data->fsel = 3;
}
