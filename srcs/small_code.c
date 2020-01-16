/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:17:55 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 23:25:22 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

int main()
{
	void *ptr;
	void *window;
	int *image;
	char *im_ad;
	int bpp;
	int size;
	int endian;

	ptr = mlx_init();
	image = mlx_new_image(ptr, 5,5);
	window = mlx_new_window(ptr, 500, 500, "small code .c");
	image[0] = 1;
	im_ad = mlx_get_data_addr(image, &bpp, &size, &endian);
	mlx_put_image_to_window(ptr, window, image, 0,0);
}