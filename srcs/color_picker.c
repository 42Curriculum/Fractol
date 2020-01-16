/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:38:30 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/16 14:16:17 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/colors.h"
#include "../mlx/mlx.h"
#include "../incl/fractol.h"
#include <stdlib.h>

void	color_pick(int iterations, int x, int y, t_data **data)
{
	int win_min;
	int win_max;
	int j_min;
	int j_max;
	int ar[11] = {BLACK, B_NUIT, B_TERNE,B_NAVAL, B_FONCE, BLUE, LIGHT_B, B_PALI, B_CIEL, B_PALI, WHITE};
	j_min = 0;
	j_max = 10;
	win_max = 100;
	win_min = 0;
	iterations = ((j_max - j_min)*(iterations - win_min) / (win_max - win_min));
	//mlx_clear_window(data->prgr, data->window);
	(*data)->image.img_adress[y * (*data)->w + x] = ar[iterations];
	
	//mlx_pixel_put((*data)->prgr, (*data)->window, (*data)->x, (*data)->y, ar[iterations]);
}