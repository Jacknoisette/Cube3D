/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:25:40 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:13:03 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	create_image(void *img_ptr, int width, int height, int color)
{
	t_image	img;
	int		pixel_offset;
	int		y;
	int		x;

	img.image_data = mlx_get_data_addr(img_ptr, &img.bpp,
			&img.size_line, &img.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel_offset = y * img.size_line + x * (img.bpp / 8);
			img.image_data[pixel_offset] = color;
			img.image_data[pixel_offset + 1] = color >> 8;
			img.image_data[pixel_offset + 2] = color >> 16;
			img.image_data[pixel_offset + 3] = 0;
			x++;
		}
		y++;
	}
	return (1);
}
