/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:50:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:03:43 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	init(t_game *game)
{
	game->map = NULL;
	game->map_path = NULL;
	game->map_fd = -1;
	game->keycode = NULL_KEY;
	game->texture.wall_texture[NO] = NULL;
	game->texture.wall_texture[SO] = NULL;
	game->texture.wall_texture[WE] = NULL;
	game->texture.wall_texture[EA] = NULL;
	game->texture.floor_color = 0x0;
	game->texture.ceiling_color = 0x0;
	game->texture.floor_image = NULL;
	game->texture.ceiling_image = NULL;
	game->texture.wall_images = NULL;
	game->start_map_line = 0;
	game->error_in_walls = false;
	return (TRUE);
}

int	parsing(t_game *game, int argc, char **argv)
{
	if (init(game) == ERROR)
		return (ERROR);
	ft_printf(1, "Init ok\n");
	if (!get_map_path(game, argc, argv))
		return (ERROR);
	ft_printf(1, "Map path : %s, fd : %i\n", game->map_path, game->map_fd);
	if (!get_map(game))
		return (ERROR);
	ft_printf(1, "Map ok\n");
	if (!access_image(game))
		return (ERROR);
	return (TRUE);
}
