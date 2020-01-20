/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:30:44 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 15:15:45 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include "../incl/colors.h"
#include <complex.h>

void	burningship(double x, double y, t_data *data)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_rtmp;

	i = 0;
	data->c.real = 1.5 * (x - data->w / 2) /
	(0.5 * data->zoom * data->w) - data->m_x;
	data->c.im = (y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y;
	z_r = data->c.real;
	z_i = data->c.im;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = fabs(z_r * z_r - z_i * z_i + data->c.real);
		z_i = fabs(2 * z_rtmp * z_i + data->c.im);
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	owo(double x, double y, t_data *data)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_rtmp;

	i = 0;
	z_r = 1.5 * (x - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_x;
	z_i = (y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = (z_r * z_r - z_i * z_i + data->c.real * 1.5) / 2;
		z_i = 2 * z_rtmp * z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	phoenix(double x, double y, t_data *data)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_i2;
	double	z_rtmp;

	i = 0;
	z_r = 1.5 * (x - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_x;
	z_i = (y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_i2 = z_i;
		z_r = z_r * z_r - z_i * z_i + data->c.real * z_rtmp;
		z_i = 2 * z_rtmp * z_i + data->c.im * z_i2;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	mandelbrot2(double x, double y, t_data *data)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_rtmp;

	i = 0;
	data->c.real = 1.5 * (x - data->w / 2) /
	(0.5 * data->zoom * data->w) - data->m_x;
	data->c.im = (y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y;
	z_r = data->c.real;
	z_i = data->c.im;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = z_r * z_r - z_i * z_i + z_r + data->c.real;
		z_i = 2 * z_rtmp * z_i + z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}
