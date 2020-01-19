/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:15:38 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/18 17:28:55 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void prgr_loop(int frac, void *mlx)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->fractal = frac;
	data->prgr = mlx;
	data->window = mlx_new_window(data->prgr, 500, 500, "Fract'ol");
	data_init(&data);
	draw_fractal(&data);
	mlx_key_hook(data->window, on_key, &data);
	mlx_hook(data->window, 6, 0, moved, &data);
	mlx_hook(data->window, 4, 0, mouse_up, &data);
	mlx_hook(data->window, 5, 0, mouse_down, &data);
	mlx_loop(data->prgr);
}

void 	def_frac(char **frac)
{
	frac[0] = ft_strdup("julia");
	frac[1] = ft_strdup("mandelbrot");
	frac[2] = ft_strdup("tom");
	frac[3] = ft_strdup("owo");
	frac[4] = ft_strdup("burningship");
	frac[5] = ft_strdup("phoenix");
	frac[6] = ft_strdup("harry");
}

int		main(int argv, char **argp)
{
	char **fractals;
	int i;
	int n;

	i = 0;
	void *mlx = mlx_init();
	fractals = (char **)malloc(sizeof(char) * 7);
	def_frac(fractals);
	if (argv == 2)
	{
		while (i < 7)
		{
			if ((n = ft_strcmp(fractals[i], ft_str_tolower(ft_strdup(argp[1]))) == 0))
				break ;
			i++;
		}
		if (i < 7)
			prgr_loop(i, mlx);
		else
			ft_putstr("Invalid name");
	}
	else
		ft_putstr("Usage : fractol fract_name\nAvailable fractals :\n*Julia"
		"\n*Mandelbrot \n*Tom \n*Owo \n*Burningship \n*Phoenix \n*Harry");
}