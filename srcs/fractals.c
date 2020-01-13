/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:56 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/12 17:13:20 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include "../incl/colors.h"
#include <complex.h>

int		draw_fractal(t_data **data)
{
	int i;
	int n;

	mlx_clear_window((*data)->prgr, (*data)->window);
	i = 0;
	while (i < 1000)
	{
		n = 0;
		while (n < 1000)
		{
			(*data)->x = n;
			(*data)->y = i;
			julia((double)n, (double)i, *data);
			n++;
		}
		i++;
	}
	return (0);
}

void	julia(double x, double y, t_data *data)
{
	int i;
	double z_r;
	double z_i;
	double c_r;
	double c_i;
	double z_rtmp;
	i = 0;
	//translate_coord(&x, &y, data);
	z_r = x;
	z_i = y;
	z_r = 1.5 * (x - data->w / 2) / (0.5 * data->zoom * data->w) + data->off_x;
	z_i = (y - data->w / 2) / (0.5 * data->zoom * data->w) + data->off_y;
	/* c_r = -0.7;
	c_i = 0.27015; */
	while (i < data->it_max && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = z_r * z_r - z_i * z_i + data->c.real;
		z_i = 2 * z_rtmp * z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}
