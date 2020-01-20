/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:23 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 14:39:03 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"

int	on_key(int key, t_data **data)
{
	if (key == K_ESC)
	{
		mlx_destroy_window((*data)->prgr, (*data)->window);
		exit(0);
	}
	if (key == K_SPACE)
		(*data)->z_mode *= -1;
	if (key == K_RETURN)
		save_file(data);
	if (key == K_LEFT)
		((*data)->color == 0) ? ((*data)->color = 2) : ((*data)->color -= 1);
	if (key == K_RIGHT)
		((*data)->color == 2) ? ((*data)->color = 0) : ((*data)->color += 1);
	if (key == K_UP)
		(*data)->max += 10;
	if (key == K_DOWN)
		(*data)->max -= 10;
	if ((*data)->max < 10)
		(*data)->max = 10;
	if ((*data)->max > 99)
		(*data)->max = 99;
	return (0);
}
