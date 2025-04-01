/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:00:57 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/01 14:51:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

void display_map_wall(t_game *game, t_ray *ray)
{
	size_t	buf_size;
	char *buffer;
	int	i;
	int	j;
	int	k;
	
	buf_size = (game->max_height + 1) * (game->max_width + 1) * 64;
	buffer = malloc(buf_size);
	 if (!buffer)
		return ;
	buffer[0] = '\0';
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j].type != '\0')
		{
			k = 0;
			while (k < WIDTH)
			{
				if (i == ray->vision_y[k] && j == ray->vision_x[k])
					strcat(buffer, "\033[32m\033[1m");
				k++;
			}
			if (i == game->player.y && j == game->player.x)
				strcat(buffer, "\033[34m\033[1m");
			strcat(buffer, &game->map[i][j].type);
			strcat(buffer, "\033[0m");
			j++;
		}
		strcat(buffer, "\n");
		i++;
	}
	i = 0;
	printf("X:%i, Y:%i, R:%i\n", (int)game->player.x,
		(int)game->player.y, (int)(90 *game->player.angle));
	printf("%s", buffer);
	free(buffer);
	while (game->map[i] != NULL)
	{
		printf("\033[F\033[J");
		i++;
	}
	printf("\033[F\033[J");
}

int	cast_ray(t_game *game, t_ray *ray)
{
	if (compute_direction(game, ray) == ERROR)
		return (ERROR);
	if (compute_distance(game, ray) == ERROR)
		return (ERROR);
	if (compute_dda(game, ray) == ERROR)
		return (ERROR);
	if (compute_wall_distance(game, ray) == ERROR)
		return (ERROR);
	if (compute_line_to_draw(game, ray) == ERROR)
		return (ERROR);
	ray->vision_y[ray->ray] = ray->map_y;
	ray->vision_x[ray->ray] = ray->map_x;
	return (TRUE);
}

int	cast_all_rays(t_game *game)
{
	t_ray	ray;

	ray.ray = 0;
	ray.prev_map_x = -1;
	ray.prev_map_y = -1;
	ray.vision_x = malloc((WIDTH + 1) * sizeof(int));
	ray.vision_y = malloc((WIDTH + 1) * sizeof(int));
	while (ray.ray < WIDTH)
	{
		if (cast_ray(game, &ray) == ERROR)
		{
			if (ray.vision_x)
				free(ray.vision_x);
			if (ray.vision_y)
				free(ray.vision_y);
			return (ERROR);
		}
		ray.ray++;
	}
	display_map_wall(game, &ray);
	if (ray.vision_x)
		free(ray.vision_x);
	if (ray.vision_y)
		free(ray.vision_y);
	return (TRUE);
}

int	rendering(t_game *game)
{
	t_image	img;

	free_img(game->session, game->renderer);
	game->renderer = mlx_new_image(game->session, WIDTH, HEIGHT);
	img.image_data = mlx_get_data_addr(game->renderer, &img.bpp,
			&img.size_line, &img.endian);
	create_imagef(game->renderer,
		WIDTH, HEIGHT, game->texture.floor_color);
	create_imagec(game->renderer, WIDTH, HEIGHT,
		game->texture.ceiling_color);
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->player.plane_x = -sin(game->player.angle) * game->fov;
	game->player.plane_y = cos(game->player.angle) * game->fov;
	cast_all_rays(game);
	mlx_put_image_to_window(game->session, game->window,
		game->renderer, 0, 0);
	return (TRUE);
}
