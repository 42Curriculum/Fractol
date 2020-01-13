/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:35 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/11 21:36:31 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/incl/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

typedef	struct	s_im
{
	double		real;
	double		im;
}				t_im;

typedef struct	s_data
{
	int			mouse_x;
	int			mouse_y;
	int			it_max;
	int			off_x;
	int			off_y;
	int			mode;
	int			w;
	int			x;
	int			y;
	double		zoom;
	void		*prgr;
	void		*window;
	t_im		c;
}				t_data;

void			translate_coord(double *x, double *y, t_data *data);
void			data_init(t_data **data);

void			prgr_loop(int frac);

int				draw_fractal(t_data **data);
void			julia(double x, double y, t_data *data);
void	new_julia(double x, double y, t_data *data);

void	color_pick(int iterations, int x, int y, t_data **data);

#endif