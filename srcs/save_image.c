/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:43:16 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/19 04:17:15 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/keys.h"
#include "../incl/fractol.h"
# define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"
#include <stdlib.h>
#include <fcntl.h>


char	*get_name(void)
{
	char	*buffer;
	int		b;

	buffer = malloc(200);
	b = read(0, buffer, 199);
	buffer[b - 1] = '\0';
	return (buffer);
}

void	save_file(t_data **data)
{
	char *filename;
	char *str;
	int fd;
	int i;
	int tmp;

	i = 0;
	if (!(open("images", O_RDONLY | O_DIRECTORY)))
		system("mkdir images");
	ft_putstr("Input file name :");
	filename = get_name();
	str = ft_better_strjoin(ft_strdup("echo "), "images/");
	str = ft_better_strjoin(str, filename);
	system(str);
	free(str);
	str = ft_better_strjoin(ft_strdup("images/"), filename);
	str = ft_better_strjoin(str, ".jpg");
	while (i < (*data)->w * (*data)->w)
	{
		
		(*data)->image.img_adress[i] = ((*data)->image.img_adress[i] & 255) << 16 |
		((*data)->image.img_adress[i] & 65280) |
		((*data)->image.img_adress[i] & 16711680) >> 16;
		i++;
	}
	stbi_write_jpg(str, (*data)->w, (*data)->w, 4, (*data)->image.img_adress, 500);
	free(filename);
	free(str);
}