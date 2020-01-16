/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:56 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/16 14:16:45 by jjosephi         ###   ########.fr       */
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
	while (i < (*data)->w)
	{
		n = 0;
		while (n < (*data)->w)
		{
			(*data)->x = n;
			(*data)->y = i;
			julia((double)n, (double)i, *data);
			n++;
		}
		i++;
	}
	//(*data)->image.image = mlx_new_image((*data)->prgr, (*data)->w, (*data)->w);
	i = 1250;
	while (i < 1350)
	{
		(*data)->image.img_adress[i] = RED;
		i++;
	}
	mlx_put_image_to_window((*data)->prgr, (*data)->window, (*data)->image.image, 0, 0);
	
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
	z_r = 1.5 * (x - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_x;
	z_i = (y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = z_r * z_r - z_i * z_i + data->c.real;
		z_i = 2 * z_rtmp * z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	mandelbrot(double x, double y, t_data *data)
{
	int i;
	double z_r;
	double z_i;
	double c_r;
	double c_i;
	double z_rtmp;
	i = 0;
	c_r = 1.5 * (x - data->w / 2) / (0.5 * data->zoom * data->w) + data->m_x;
	c_i = (y - data->w / 2) / (0.5 * data->zoom * data->w) + data->m_y;
	z_r = c_r;
	z_i = c_i;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_rtmp * z_i + c_i;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}
