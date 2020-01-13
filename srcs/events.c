/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:42 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/12 17:17:34 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"
#include"../incl/colors.h"
#include <stdio.h>

static void mouse_scroll(int key, t_data **data)
{
	printf("It : %d", (*data)->it_max);
	if ((*data)->mode == -1)
	{
		if (key == K_SCROLL_D)
			(*data)->zoom += 0.5;
		if (key == K_SCROLL_U)
			(*data)->zoom -= 0.5;
	}
	else
	{
		if (key == K_SCROLL_D)
			(*data)->it_max += 10;
		if (key == K_SCROLL_U)
			(*data)->it_max -= 10;
	}
}

static int	show_coord(int key, int x, int y, t_data **data)
{
	double x_;
	double y_;

	x_ = (double)x;
	y_=	(double)y_;
	if (key == K_SPACE)
		(*data)->mode *= -1;
	mouse_scroll(key, data);
	(*data)->off_x = 0;
	(*data)->off_y = 0;
	translate_coord(&x_, &y_, *data);
	(*data)->off_x = x_;
	(*data)->off_y = y_;
	draw_fractal(data);
	return (0);
}

int 	moved(int x, int y, t_data **data)
{
	double x_;
	double y_;

	x_ = (double)x;
	y_ = (double)y;
	if (x < (*data)->w && x > 0 && y < (*data)->w && y > 0 &&
	(*data)->mode == 1)
	{
		translate_coord(&x_,&y_, *data);
		(*data)->c.real = x_;
		//(*data)->c.im = y_;
		draw_fractal(data);
	}
	return 0;
}

void		prgr_loop(int frac)
{
	t_data *data;
	
	data = (t_data *)malloc(sizeof(t_data));
	data_init(&data);
	draw_fractal(&data);
	mlx_mouse_hook(data->window, show_coord, &data);
	mlx_hook(data->window, 6, 0, moved, &data);
	mlx_loop(data->prgr);
}
