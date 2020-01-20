/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:15:38 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/20 15:21:45 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	prgr_loop(int frac, void *mlx, char **fr)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->fractal = frac;
	data->f_ar = fr;
	data->prgr = mlx;
	data->window = mlx_new_window(data->prgr, 500, 500, "Fract'ol");
	data_init(&data);
	mlx_key_hook(data->window, on_key, &data);
	mlx_hook(data->window, 6, 0, moved, &data);
	mlx_hook(data->window, 4, 0, mouse_up, &data);
	mlx_hook(data->window, 5, 0, mouse_down, &data);
	draw_fractal(&data);
	mlx_loop(data->prgr);
}

void	def_frac(char **frac)
{
	frac[0] = "Julia";
	frac[1] = "Mandelbrot";
	frac[2] = "Tom";
	frac[3] = "Owo";
	frac[4] = "Burningship";
	frac[5] = "Phoenix";
	frac[6] = "Harry";
}

int		check_input(char *argv, char **frac)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if ((ft_strcmp(frac[i], argv) == 0))
			break ;
		i++;
	}
	if (i < 7)
		return (i);
	else
		return (-1);
}

int		main(int argv, char **argp)
{
	void	*mlx;
	char	**fractals;
	int		i;

	i = 0;
	fractals = (char **)malloc(sizeof(char *) * 7);
	def_frac(fractals);
	if (argv == 2)
	{
		if ((i = check_input(argp[1], fractals)) >= 0)
		{
			mlx = mlx_init();
			prgr_loop(i, mlx, fractals);
		}
		else
			ft_putstr("Invalid fractal\nAvailable fractals :\n*Julia"
		"\n*Mandelbrot \n*Tom \n*Owo \n*Burningship \n*Phoenix \n*Harry");
	}
	else
		ft_putstr("Usage : fractol fract_name\nAvailable fractals :\n*Julia"
		"\n*Mandelbrot \n*Tom \n*Owo \n*Burningship \n*Phoenix \n*Harry");
}
