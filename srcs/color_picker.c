/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:38:30 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/18 21:34:25 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/colors.h"
#include "../mlx/mlx.h"
#include "../incl/fractol.h"
#include <stdlib.h>

void	def_blue(t_colors *color)
{
	int i;
	unsigned int er;   //(x & 0x00ff0000) >> 16;
	unsigned int eg; //(x & 0x0000ff00) >> 8;
	unsigned int eb; // (x & 0x000000ff);
	
	er = (((B_PALE & 0x00ff0000) >> 16) - ((BLACK & 0x00ff0000) >> 16)) / 100;
	eg = (((B_PALE & 0x0000ff00) >> 8) - ((BLACK & 0x0000ff00) >> 8)) / 100;
	eb = ((B_PALE & 0x000000ff) - (BLACK & 0x000000ff)) / 100;
	color->r = ((BLACK & 0x00ff0000) >> 16);
	color->g = ((BLACK & 0x0000ff00) >> 8);
	color->b = (BLACK & 0x000000ff);
	i = 0;
	while (i < 100)
	{
		color->blue[i] = (((color->r << 8) + color->g) << 8) + color->b;
		color->r += er;
		color->g += eg;
		color->b += eb;
		i++;
	}
}


void	def_gold(t_colors *color)
{
	int i;
	unsigned int er;   //(x & 0x00ff0000) >> 16;
	unsigned int eg; //(x & 0x0000ff00) >> 8;
	unsigned int eb; // (x & 0x000000ff);
	
	er = ((((WHITE & 0x00ff0000) >> 16) - ((B_NAVAL& 0x00ff0000) >> 16)));
	eg = ((((WHITE & 0x0000ff00) >> 8) - ((B_NAVAL & 0x0000ff00) >> 8)));
	eb = (((WHITE& 0x000000ff) - (B_NAVAL & 0x000000ff)));
	color->r = (WHITE & 0x00ff0000) * er + (WHITE & 0x0000ff00) * er + (WHITE & 0x000000ff) * er;
	color->r /= 100;
	i = 0;
	while (i < 100)
	{
		color->gold[i] = (((color->r << 8) + color->g) << 8) + color->b;
		color->r += er;
		color->g += eg;
		color->b += eb;
		i++;
	}
}

void	def_green(t_colors *color)
{
	int r;
	int g;
	int b;
	int step;
	int i;
	unsigned int er;   //(x & 0x00ff0000) >> 16;
	unsigned int eg; //(x & 0x0000ff00) >> 8;
	unsigned int eb;

	er = (255 - 0)/100; //((WHITE & 0x00ff0000) >> 16) - ((RED & 0x00ff0000) >> 16);
	eg = (255 - 255)/100;//((WHITE & 0x0000ff00) >> 8) - ((RED & 0x0000ff00) >> 8);
	eb = (255 - 0)/100;//(WHITE& 0x000000ff) - (RED & 0x000000ff);
	r = (((WHITE & 0x00ff0000) >> 16));
	g = (((WHITE & 0x0000ff00) >> 8));
	b = ((WHITE & 0x000000ff));
	i = 0;
	while (i < 100)
	{
		color->red[i] = ((((r << 8) + g) << 8) + b);
		r += er;
		g += eg;
		b += eb;
		i++;
	}
}

void	def_red(t_colors *color)
{
	int r;
	int g;
	int b;
	int step;
	int i;
	unsigned int er;   //(x & 0x00ff0000) >> 16;
	unsigned int eg; //(x & 0x0000ff00) >> 8;
	unsigned int eb;

	er = (255 - 255)/5; //((WHITE & 0x00ff0000) >> 16) - ((RED & 0x00ff0000) >> 16);
	eg = (255 - 128)/5;//((WHITE & 0x0000ff00) >> 8) - ((RED & 0x0000ff00) >> 8);
	eb = (255 - 0)/5;//(WHITE& 0x000000ff) - (RED & 0x000000ff);
	r = (((WHITE & 0x00ff0000) >> 16));
	g = (((WHITE & 0x0000ff00) >> 8));
	b = ((WHITE & 0x000000ff));
	i = 0;
	while (i < 100)
	{;
		color->red[i] = ((((r << 8) + g) << 8) + b);
		r += er;
		g += eg;
		b += eb;
		i++;
	}
}

void	define_colors(t_colors *colors)
{
	int i;
	unsigned int r;
	unsigned int g;
	unsigned int b;

	def_blue(colors);
	def_gold(colors);
	def_red(colors);
	def_green(colors);
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
		define_colors(colors);
	}
	j_min = 0;
	j_max = 100;
	win_max = (*data)->it_max;
	win_min = 0;
	iterations = ((j_max - j_min) * (iterations - win_min) / (win_max - win_min));
	(*data)->image.img_adress[y * (*data)->w + x] = colors->colors[(*data)->color][iterations];
}