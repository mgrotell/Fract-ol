/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:23:49 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/30 16:34:21 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

void			resetv(t_map *data)
{
	data->creal = 1.5 * (data->x - WIN_W / 2) /
		(0.5 * data->zoom * WIN_W) + data->movex;
	data->cimag = (data->y - WIN_H / 2) /
		(0.5 * data->zoom * WIN_H) + data->movey;
	data->newi = 0;
	data->newr = 0;
	data->oldi = 0;
	data->oldr = 0;
	data->iter = 0;
}

long double		getabs(long double num)
{
	return (num < 0 ? -num : num);
}

void			drawburningship(t_map *data)
{
	data->x = 0;
	while (data->x < WIN_W)
	{
		resetv(data);
		while (data->iter < data->maxiter)
		{
			data->oldr = data->newr;
			data->oldi = data->newi;
			data->newr = getabs(data->oldr * data->oldr -
					data->oldi * data->oldi + data->creal);
			data->newi = getabs(2 * data->oldr * data->oldi
					+ data->cimag);
			if (data->newr * data->newr +
					data->newi * data->newi > 4)
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

void			*burningship(void *arg)
{
	t_map	*data;

	data = (t_map*)arg;
	while (data->y < data->y_m)
	{
		drawburningship(data);
		data->y++;
	}
	return (0);
}
