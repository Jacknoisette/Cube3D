/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:42:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/01 13:54:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

void	compute_img(t_ray *ray, t_game *game, t_texture_display *display)
{
	if (ray->side == 0)
		display->wall_x = game->player.y + ray->wall_distance * ray->ray_dir_y;
	else
		display->wall_x = game->player.x + ray->wall_distance * ray->ray_dir_x;
	display->wall_x -= floor(display->wall_x);
	display->texture_x = fmin((int)(display->wall_x * (double)SIZE), SIZE - 1);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		display->texture_x = SIZE - display->texture_x - 1;
	display->step = 1.0 * SIZE / ray->line_height;
	display->texture_pos = (ray->draw_start - HEIGHT
			/ 2 + ray->line_height / 2) * display->step;
	display->y = ray->draw_start;
}

void	draw_pixel(t_texture_display *display, t_ray *ray, t_image *img,
			t_image *texture)
{
	display->texture_y = (int)display->texture_pos % SIZE;
	display->texture_pos += display->step;
	display->texture_offset = display->texture_y * texture->size_line
		+ display->texture_x * (texture->bpp / 8);
	display->color = *(int *)(texture->image_data + display->texture_offset);
	display->pixel_offset = display->y * img->size_line
		+ ray->ray * (img->bpp / 8);
	img->image_data[display->pixel_offset] = display->color;
	img->image_data[display->pixel_offset + 1] = display->color >> 8;
	img->image_data[display->pixel_offset + 2] = display->color >> 16;
	img->image_data[display->pixel_offset + 3] = 0;
	display->y++;
}

void	draw_vertical_line_img(void *img_ptr, t_ray *ray, t_game *game)
{
	t_texture_display	display;
	t_image				img;
	t_image				texture;
	void				*texture_ptr;

	img.image_data = mlx_get_data_addr(img_ptr, &img.bpp,
			&img.size_line, &img.endian);
	if (img.image_data == NULL)
		return ;
	texture_ptr = game->texture.wall_images[ray->n_texture];
	if (texture_ptr == NULL)
		return ;
	texture.image_data = mlx_get_data_addr(texture_ptr, &texture.bpp,
			&texture.size_line, &texture.endian);
	if (texture.image_data == NULL)
		return ;
	compute_img(ray, game, &display);
	while (display.y < ray->draw_end)
		draw_pixel(&display, ray, &img, &texture);
}
