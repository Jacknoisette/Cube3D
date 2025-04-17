/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:50:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/01 13:43:59 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

void	init_textures(t_game *game)
{
	game->texture.wall_texture[NO] = NULL;
	game->texture.wall_texture[SO] = NULL;
	game->texture.wall_texture[WE] = NULL;
	game->texture.wall_texture[EA] = NULL;
	game->texture.wall_images[NO] = NULL;
	game->texture.wall_images[SO] = NULL;
	game->texture.wall_images[WE] = NULL;
	game->texture.wall_images[EA] = NULL;
	game->texture.floor_color = 0x0;
	game->texture.ceiling_color = 0x0;
}

int	init(t_game *game)
{
	game->map = NULL;
	game->map_path = NULL;
	game->map_fd = -1;
	game->keycode = NULL_KEY;
	init_textures(game);
	game->renderer = NULL;
	game->texture.floor_image = NULL;
	game->texture.ceiling_image = NULL;
	game->start_map_line = 0;
	game->error_in_walls = false;
	game->fov = M_PI / 5;
	return (TRUE);
}

int	parsing(t_game *game, int argc, char **argv)
{
	if (init(game) == ERROR)
		return (ERROR);
	if (!get_map_path(game, argc, argv))
		return (ERROR);
	if (!get_map(game))
		return (ERROR);
	if (!access_image(game))
		return (ERROR);
	find_map_limit(game);
	return (TRUE);
}
