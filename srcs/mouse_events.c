/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:42 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 14:30:08 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"
#include <stdio.h>

int	mouse_up(int key, int x, int y, t_data **data)
{
	double x_;
	double y_;

	translate_coord(&x_, *data);
	translate_coord(&y_, *data);
	if (key == K_MOUSE1)
		(*data)->mode = 1;
	if (key == K_SCROLL_U)
		(*data)->zoom += 0.2;
	if (key == K_SCROLL_D)
		(*data)->zoom -= 0.2;
	draw_fractal(data);
	return (1);
}

int	mouse_down(int key, int x, int y, t_data **data)
{
	if (key == K_MOUSE1)
		(*data)->mode = -1;
	return (1);
}

int	moved(int x, int y, t_data **data)
{
	double x_;
	double y_;

	x_ = (double)x;
	y_ = (double)y;
	if (x < (*data)->w && x > 0 && y < (*data)->w && y > 0)
	{
		if ((*data)->mode == -1 && (*data)->z_mode == -1)
		{
			translate_coord(&x_, *data);
			(*data)->c.real = x_;
			translate_coord(&y_, *data);
			(*data)->c.im = y_;
			draw_fractal(data);
		}
		else if ((*data)->mode == 1)
		{
			translate_coord(&x_, *data);
			(*data)->m_x = x_;
			translate_coord(&y_, *data);
			(*data)->m_y = y_;
			draw_fractal(data);
		}
	}
	return (0);
}
