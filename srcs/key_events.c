/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:23 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 15:03:48 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"
#include <stdio.h>

int	on_key(int key, t_data **data)
{
	if (key == K_ESC)
	{
		mlx_destroy_window((*data)->prgr, (*data)->window);
		exit(0);
	}
	return (0);
}