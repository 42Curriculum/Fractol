/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:23 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 22:43:32 by jjosephi         ###   ########.fr       */
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
	{
		(*data)->z_mode *= -1;
	}
	if (key == K_RETURN)
	{
		(*data)->z_mode *= -1;
	}
	return (0);
}