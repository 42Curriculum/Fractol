/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:25:05 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/18 21:32:54 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define WHITE 	0xFfFfFf
# define BLACK 0x000000

# define RED 	0xFF0000
# define GREEN 	0x00FF00
# define YELLOW 0xFFFF00
# define ORANGE 0xFF8000
# define VIOLET 0x7F00FF
# define SILVER	0xC0C0C0
# define GREY	0x808080
# define MAROON	0x800000
# define OLIVE	0x808000
# define PURPLE	0x800080
# define TEAL	0x008080
# define NAVY	0x000080


/* Blues */

# define B_NUIT 0x000033
# define B_TERNE 0x000066
# define B_NAVAL 0x000099
# define B_FONCE 0x0000cc
# define BLUE 0x0000ff
# define LIGHT_B 0x3232ff
# define B_PALI 0x6666ff
# define B_CIEL 0x9999ff
# define B_PALE 0xccccff

typedef struct s_colors
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	int **colors;
	int blue[100];
	int red[100];
	int green[100];
	int gold[100];
}				t_colors;

#endif
