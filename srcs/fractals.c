/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:56 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 15:12:30 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include "../incl/colors.h"
#include <complex.h>

int		draw_fractal(t_data **data)
{
	int				i;
	int				n;
	static t_func	*ar;

	if (!(ar))
		ar = f_array((*data)->fractal);
	mlx_clear_window((*data)->prgr, (*data)->window);
	i = 0;
	while (i < (*data)->w)
	{
		n = 0;
		while (n < (*data)->w)
		{
			(*data)->x = n;
			(*data)->y = i;
			ar((double)n, (double)i, *data);
			n++;
		}
		i++;
	}
	mlx_put_image_to_window((*data)->prgr, (*data)->window,
	(*data)->image.image, 0, 0);
	return (0);
}

void	mandelbrot(double x, double y, t_data *data)
{
	int		i;
	double	z_r;
	double	z_i;
	double	z_rtmp;

	i = 0;
	data->c.real = (1.5 * (x - data->w / 2) /
	(0.5 * data->zoom * data->w) - data->m_x);
	data->c.im = ((y - data->w / 2) / (0.5 * data->zoom * data->w) - data->m_y);
	z_r = data->c.real;
	z_i = data->c.im;
	while (i < 100 && (z_r * z_r + z_i * z_i) <= 4)
	{
		z_rtmp = z_r;
		z_r = z_r * z_r - z_i * z_i + data->c.real;
		z_i = 2 * z_rtmp * z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	julia(double x, double y, t_data *data)
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
		z_r = z_r * z_r - z_i * z_i + data->c.real;
		z_i = 2 * z_rtmp * z_i + data->c.im;
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}

void	mxjulia(double x, double y, t_data *data)
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
		z_r = fabs(z_r * z_r - z_i * z_i + data->c.real);
		z_i = fabs(2 * z_rtmp * z_i + data->c.im);
		i++;
	}
	color_pick(i, data->x, data->y, &data);
}
