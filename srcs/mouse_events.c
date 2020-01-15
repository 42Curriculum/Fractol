/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:42 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 14:54:11 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"
#include <stdio.h>

static int mouse_up(int key, int x, int y, t_data **data)
{
	if (key == K_MOUSE1)
		(*data)->mode = 1;
	
	return (1);
}

static int mouse_down(int key, int x, int y,t_data **data)
{
	if (key == K_MOUSE1)
		(*data)->mode = -1;
	else if (key == K_ESC)
	{
		mlx_destroy_window((*data)->prgr, (*data)->window);
		exit(0);
	}
	if (key == K_SCROLL_U)
		(*data)->zoom += 0.5;
	if (key == K_SCROLL_D)
		(*data)->zoom -= 0.5;
	
	return (1);
}

int 	moved(int x, int y, t_data **data)
{
	double x_;
	double y_;

	x_ = (double)x;
	y_ = (double)y;
	if (x < (*data)->w && x > 0 && y < (*data)->w && y > 0)
	{
		if ((*data)->mode == -1)
		{
			translate_coord(&x_,*data);
			(*data)->c.real = x_;
			translate_coord(&y_,*data);
			(*data)->c.im = y_;
			draw_fractal(data);
		}
		else if ((*data)->mode == 1)
		{
			translate_coord(&x_,*data);
			(*data)->m_x = x_;
			translate_coord(&y_,*data);
			(*data)->m_y = y_;
			draw_fractal(data);
		}
	}
	return (0);
}

void		prgr_loop(int frac)
{
	t_data *data;
	
	data = (t_data *)malloc(sizeof(t_data));
	data_init(&data);
	draw_fractal(&data);
	mlx_key_hook(data->window, on_key, &data);
	mlx_hook(data->window, 6, 0, moved, &data);
	mlx_hook(data->window, 4, 0, mouse_up, &data);
	mlx_hook(data->window, 5, 0, mouse_down, &data);
	mlx_loop(data->prgr);
}
