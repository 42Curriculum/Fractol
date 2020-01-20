/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:23:13 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 14:57:18 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include "../incl/keys.h"

t_func	*f_array(int i)
{
	t_func *ar[7];

	ar[0] = &julia;
	ar[1] = &mandelbrot;
	ar[2] = &mxjulia;
	ar[3] = &owo;
	ar[4] = &burningship;
	ar[5] = &phoenix;
	ar[6] = &mandelbrot2;
	return (ar[i]);
}

void	data_init(t_data **data)
{
	(*data)->mouse_x = 0;
	(*data)->mouse_y = 0;
	(*data)->it_max = 100;
	(*data)->mode = -1;
	(*data)->w = 500;
	(*data)->zoom = 1.0;
	(*data)->c.im = 0.27015;
	(*data)->c.real = -0.7;
	(*data)->image.image = mlx_new_image((*data)->prgr, (*data)->w, (*data)->w);
	(*data)->image.img_adress = (int *)mlx_get_data_addr(
	(void*)(*data)->image.image, &(*data)->image.bpp, &(*data)->image.line_s,
	&(*data)->image.endian);
	(*data)->z_mode = 1;
	(*data)->m_x = 0;
	(*data)->color = 0;
	(*data)->max = 10;
}

void	translate_coord(double *x, t_data *data)
{
	int win_min;
	int win_max;
	int j_min;
	int j_max;

	j_min = -1;
	j_max = 1;
	win_max = data->w;
	win_min = 0;
	*x = ((j_max - j_min) * (*x - win_min) / (win_max - win_min));
	*x += j_min;
}
