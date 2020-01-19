/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:38:30 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/19 04:42:45 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/colors.h"
#include "../mlx/mlx.h"
#include "../incl/fractol.h"
#include <stdlib.h>

void	def_blue(t_colors *color, t_data **data)
{
	int i;
	unsigned int er;
	unsigned int eg;
	unsigned int eb;
	
	er = (((B_PALE & 0x00ff0000) >> 16) - ((WHITE & 0x00ff0000) >> 16)) / (*data)->max;
	eg = (((B_PALE & 0x0000ff00) >> 8) - ((WHITE & 0x0000ff00) >> 8)) / (*data)->max;
	eb = ((B_PALE & 0x000000ff) - (WHITE & 0x000000ff)) / (*data)->max;
	color->r = ((BLACK & 0x00ff0000) >> 16);
	color->g = ((BLACK & 0x0000ff00) >> 8);
	color->b = (BLACK & 0x000000ff);
	i = 0;
	while (i < (*data)->max)
	{
		color->blue[i] = (((color->r << 8) + color->g) << 8) + color->b;
		color->r += er;
		color->g += eg;
		color->b += eb;
		i++;
	}
}


void	def_gold(t_colors *color, t_data **data)
{
	int i;
	unsigned int er;
	unsigned int eg;
	unsigned int eb;
	
	er = ((((WHITE & 0x00ff0000) >> 16) - ((OLIVE& 0x00ff0000) >> 16)));
	eg = ((((WHITE & 0x0000ff00) >> 8) - ((OLIVE & 0x0000ff00) >> 8)));
	eb = (((WHITE & 0x000000ff) - (OLIVE & 0x000000ff)));
	color->r = ((OLIVE & 0x00ff0000) >> 16) / 99;
	color->g = ((OLIVE & 0x0000ff00) >> 8) / 99;
	color->b = (OLIVE & 0x000000ff) / 99;
	i = 0;
	while (i < 99)
	{
		color->gold[i] = (((color->r << 8) + color->g) << 8) + color->b;
		color->r += er;
		color->g += eg;
		color->b += eb;
		i++;
	}
}

void	def_green(t_colors *color, t_data **data)
{
	int r;
	int g;
	int b;
	int step;
	int i;
	unsigned int er;
	unsigned int eg;
	unsigned int eb;

	er = (255 - 0) / (*data)->max;
	eg = (255 - 255) / (*data)->max;
	eb = (255 - 0) / (*data)->max;
	r = (((WHITE & 0x00ff0000) >> 16));
	g = (((WHITE & 0x0000ff00) >> 8));
	b = ((WHITE & 0x000000ff));
	i = 0;
	while (i < (*data)->max)
	{
		color->red[i] = ((((r << 8) + g) << 8) + b);
		r += er;
		g += eg;
		b += eb;
		i++;
	}
}

void	def_red(t_colors *color, t_data **data)
{
	int i;
	int er;
	int eg;
	int eb;

	er = (255 - 255) / (*data)->max;
	eg = (255) / (*data)->max;
	eb = (255) / (*data)->max;
	color->r = (((WHITE & 0x00ff0000) >> 16));
	color->g = (((WHITE & 0x0000ff00) >> 8));
	color->b = ((WHITE &  0x000000ff));
	i = (*data)->max;
	while (i > 0)
	{
		color->red[i] = ((((color->r << 8) + color->g) << 8) + color->b);
		color->r -= er;
		color->g += eg;
		color->b += eb;
		i--;
	
	}
}

void	define_colors(t_colors *colors, t_data **data)
{
	int i;
	unsigned int r;
	unsigned int g;
	unsigned int b;

	def_blue(colors, data);
	def_gold(colors, data);
	def_red(colors, data);
	def_green(colors, data);
	colors->colors = (int **)malloc(sizeof(int *) * 4);
	colors->colors[0] = colors->blue;
	colors->colors[1] = colors->red; 
	colors->colors[2] = colors->green; 
	colors->colors[3] = colors->gold; 	
}

void	color_pick(int iterations, int x, int y, t_data **data)
{
	int win_min;
	int win_max;
	int j_min;
	int j_max;
	static t_colors *colors;

	if (!(colors))
	{
		colors = (t_colors *)malloc(sizeof(t_colors));
		define_colors(colors, data);
	}
	(*data)->col_stru = colors;
	j_min = 0;
	j_max = 100;
	win_max = (*data)->max;
	win_min = 0;
	iterations = ((j_max - j_min) * (iterations - win_min) / (win_max - win_min));
	(*data)->image.img_adress[y * (*data)->w + x] = colors->colors[(*data)->color][iterations];
}