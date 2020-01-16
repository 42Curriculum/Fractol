/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:43:16 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/15 23:16:11 by jjosephi         ###   ########.fr       */
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

void	save_file(t_data *data)
{
	char *filename;
	char *str;
	int fd;

	if (open("images", O_RDONLY | O_DIRECTORY))
		system("mkdir images");
	ft_putstr("Input file name :");
	filename = get_name();;
	str = ft_better_strjoin(ft_strdup("echo "), "images/");
	str = ft_better_strjoin(str, filename);
	system(str);
	free(str);
	str = ft_better_strjoin("images/", filename);
	stbi_write_jpg(filename, data->w, data->w, 3, data->image.image, data->w * 3);
	free(filename);
	free(str);
}