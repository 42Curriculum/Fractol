/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:23:13 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 14:08:58 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include "../incl/keys.h"

t_func	*f_array()
{
	t_func *ar[3];

	ar[0] = &julia;
	ar[1] = &mandelbrot;
	
}

void	data_init(t_data **data)
{
	(*data)->prgr = mlx_init();
	(*data)->window = mlx_new_window((*data)->prgr, 500, 500, "Fract'ol");
	(*data)->mouse_x = 0;
	(*data)->mouse_y = 0;
	(*data)->it_max = 100;
	(*data)->off_x = 0;
	(*data)->off_y = 0;
	(*data)->mode = -1;
	(*data)->w = 500;
	(*data)->zoom = 1.0;
	(*data)->c.im = 0.27015;
	(*data)->c.real = -0.7;
	(*data)->image.image = mlx_new_image((*data)->prgr, (*data)->w, (*data)->w);
	(*data)->m_x = 0;
	(*data)->m_y = 0;
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
	*x = ((j_max - j_min)*(*x - win_min) / (win_max - win_min));
	*x += j_min;
}
