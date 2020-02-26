/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:25:10 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/30 15:19:16 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/frac.h"

int		renderjulia(t_map *data)
{
	pthread_t	threads[THREADS];
	t_map		data_r[THREADS];
	int			x;

	x = 0;
	while (x < THREADS)
	{
		ft_memcpy((void*)&data_r[x], (void*)data, sizeof(t_map));
		data_r[x].y = x * (WIN_H / THREADS);
		data_r[x].y_m = (x + 1) * (WIN_H / THREADS);
		pthread_create(&threads[x], NULL, julia, &data_r[x]);
		x++;
	}
	while (x--)
		pthread_join(threads[x], NULL);
	mlx_put_image_to_window(data->mlx, data->fracwin, data->img, 0, 0);
	return (0);
}

int		rendermandelbrot(t_map *data)
{
	pthread_t	threads[THREADS];
	t_map		data_r[THREADS];
	int			x;

	x = 0;
	while (x < THREADS)
	{
		ft_memcpy((void*)&data_r[x], (void*)data, sizeof(t_map));
		data_r[x].y = x * (WIN_H / THREADS);
		data_r[x].y_m = (x + 1) * (WIN_H / THREADS);
		pthread_create(&threads[x], NULL, mandelbrot, &data_r[x]);
		x++;
	}
	while (x--)
		pthread_join(threads[x], NULL);
	mlx_put_image_to_window(data->mlx, data->fracwin, data->img, 0, 0);
	return (0);
}

int		renderburningship(t_map *data)
{
	pthread_t	threads[THREADS];
	t_map		data_r[THREADS];
	int			x;

	x = 0;
	while (x < THREADS)
	{
		ft_memcpy((void*)&data_r[x], (void*)data, sizeof(t_map));
		data_r[x].y = x * (WIN_H / THREADS);
		data_r[x].y_m = (x + 1) * (WIN_H / THREADS);
		pthread_create(&threads[x], NULL, burningship, &data_r[x]);
		x++;
	}
	while (x--)
		pthread_join(threads[x], NULL);
	mlx_put_image_to_window(data->mlx, data->fracwin, data->img, 0, 0);
	return (0);
}
