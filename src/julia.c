/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:24:03 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/30 15:20:01 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

void	calcir(t_map *data)
{
	data->newr = 1.5 * (data->x - WIN_W / 2) / (0.5 *
			data->zoom * WIN_W) + data->movex;
	data->newi = (data->y - WIN_H / 2) / (0.5 *
			data->zoom * WIN_H) + data->movey;
	data->iter = 0;
}

void	drawjulia(t_map *data)
{
	data->x = 0;
	while (data->x < WIN_W)
	{
		calcir(data);
		while (data->iter < data->maxiter)
		{
			data->oldr = data->newr;
			data->oldi = data->newi;
			data->newr = data->oldr * data->oldr - data->oldi *
				data->oldi + data->creal;
			data->newi = 2 * data->oldr * data->oldi + data->cimag;
			if (data->newr * data->newr + data->newi * data->newi > 4)
				break ;
			data->iter++;
		}
		data->x++;
		if (data->iter == data->maxiter)
			data->addrdat[data->y * WIN_W + data->x] = 0;
		else
			data->addrdat[data->y * WIN_W + data->x] =
				data->color * data->iter;
	}
}

void	*julia(void *arg)
{
	t_map	*data;

	data = (t_map*)arg;
	while (data->y < data->y_m)
	{
		drawjulia(data);
		data->y++;
	}
	return (0);
}
