/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:29:12 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/31 13:15:41 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H
# define THREADS 8
# define WIN_H 500
# define WIN_W 550

# include "../minilibx/mlx.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <pthread.h>
# include <math.h>

typedef struct		s_map
{
	void			*mlx;
	void			*fracwin;
	void			*img;
	int				bpp;
	int				endian;
	int				linesize;
	int				fsel;
	int				*addrdat;
	int				color;
	int				corec;
	int				x;
	int				y;
	int				y_m;
	int				space;
	int				mst;
	int				msposx;
	int				msposy;
	long double		creal;
	long double		cimag;
	long double		zoom;
	long double		movex;
	long double		movey;
	long double		newr;
	long double		newi;
	long double		oldr;
	long double		oldi;
	long long int	maxiter;
	long long int	iter;
}					t_map;

void				initalljulia(t_map *data);
void				initallburningships(t_map *data);
void				initallmandelbrot(t_map *data);
void				frselren(t_map *data);
void				initmlx(t_map *data);
void				*julia(void *arg);
void				*mandelbrot(void *arg);
void				*burningship(void *arg);
int					keyboard(int key, t_map *data);
int					renderjulia(t_map *data);
int					rendermandelbrot(t_map *data);
int					renderburningship(t_map *data);
int					mouse_win1(int x, int y, t_map *data);
int					mouse_win2(int button, int x, int y, t_map *data);

#endif
