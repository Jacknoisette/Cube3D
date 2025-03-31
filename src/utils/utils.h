/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:59:13 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/31 14:53:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minilbx/mlx.h"
# include "stdlib.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_map	t_map;

typedef struct s_image
{
	char	*image_data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

//IMAGE
int		create_image(void *img_ptr, int width, int height, int color);
int		create_imagef(void *img_ptr, int width, int height, int color);
int		create_imagec(void *img_ptr, int width, int height, int color);

void	draw_vertical_line(void *img_ptr, int x, int start,
			int end, int color);


//CLEANING
void	free_img(void *mlx, void *img);
void	free_charpp(char **str);
void	free_mappp(t_map ***map);

#endif