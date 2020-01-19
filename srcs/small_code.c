/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:17:55 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/18 21:16:30 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* # define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"*/
#include "../mlx/mlx.h"
#include "../incl/fractol.h"
#include "../incl/colors.h"

int main()
{
	void *ptr;
	void *window;
	int *image;
	char *im_ad;
	int ar[100];
	int bpp;
	int size;
	int endian;

	//ptr = mlx_init();
	//image = mlx_new_image(ptr, 5,5);
	//window = mlx_new_window(ptr, 500, 500, "small code .c");
	//image[0] = 1;
	//im_ad = mlx_get_data_addr(image, &bpp, &size, &endian);
	
	//stbi_write_jpg("test", 500, 500, 3, image, 500 * 3);
	int r;
	int g;
	int b;
	int step;
	int i;
	unsigned int er;   //(x & 0x00ff0000) >> 16;
	unsigned int eg; //(x & 0x0000ff00) >> 8;
	unsigned int eb; // (x & 0x000000ff);
	
	er = (255 - 255)/5; //((WHITE & 0x00ff0000) >> 16) - ((RED & 0x00ff0000) >> 16);
	eg = (255 - 128)/5;//((WHITE & 0x0000ff00) >> 8) - ((RED & 0x0000ff00) >> 8);
	eb = (255 - 0)/5;//(WHITE& 0x000000ff) - (RED & 0x000000ff);
	r = (((WHITE & 0x00ff0000) >> 16));
	g = (((WHITE & 0x0000ff00) >> 8));
	b = ((WHITE & 0x000000ff));
	i = 0;
	ft_putnbr((int)step);
	ft_putstr("er : ");
	ft_putnbr(er);
	while (i < 5)
	{
		ft_putchar('\n');
		step = ((((r << 8) + g) << 8) + b);
		ft_putchar('[');
		ft_putnbr(r);
		ft_putchar(',');
		ft_putnbr(g);
		ft_putchar(',');
		ft_putnbr(b);
		ft_putchar(']');
		ft_putchar('\n');
		r += er;
		g += eg;
		b += eb;
		i++;
	}
	//mlx_put_image_to_window(ptr, window, image, 0,0);
	//mlx_loop(ptr);
}