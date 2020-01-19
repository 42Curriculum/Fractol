/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:35 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/18 21:30:54 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/incl/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

typedef	struct	s_im
{
	double		real;
	double		im;
}				t_im;

typedef struct s_image
{
	int 		*img_adress;
	int			*image;
	int			endian;
	int			line_s;
	int			bpp;
}				t_image;

typedef struct	s_data
{
	void		*prgr;
	void		*window;
	int			mouse_x;
	int			mouse_y;
	int			fractal;
	int			it_max;
	int			mode;
	int			w;
	int			x;
	int			y;
	int			z_mode;
	int			color;
	double		zoom;
	double		m_x;
	double		m_y;
	
	t_im		c;
	t_image		image;
}				t_data;

typedef void 	t_func(double x, double y, t_data *data);

t_func			*f_array(int i);
void			translate_coord(double *x,t_data *data);
void			data_init(t_data **data);

int 		mouse_down(int key, int x, int y, t_data **data);
int 		mouse_up(int key, int x, int y, t_data **data);
int 			moved(int x, int y, t_data **data);

int				on_key(int key, t_data **data);

int				draw_fractal(t_data **data);
void			julia(double x, double y, t_data *data);
void			mandelbrot(double x, double y, t_data *data);
void			owo(double x, double y, t_data *data);
void			mandelbrot2(double x, double y, t_data *data);
void			mxjulia(double x, double y, t_data *data);
void			phoenix(double x, double y, t_data *data);
void			burningship(double x, double y, t_data *data);

void			save_file(t_data **data);

void			color_pick(int iterations, int x, int y, t_data **data);

#endif