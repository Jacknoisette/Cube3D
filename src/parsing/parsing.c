/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:50:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	init(t_game *game)
{
	game->keycode = NULL_KEY;
	game->texture.north_texture = NULL;
	game->texture.south_texture = NULL;
	game->texture.west_texture = NULL;
	game->texture.east_texture = NULL;
	game->texture.floor_color = 0x0;
	game->texture.ceiling_color = 0x0;
	return (TRUE);
}

int	parsing(t_game *game, int argc, char **argv)
{
	if (init(game) == ERROR)
		return (ERROR);
	ft_printf(1, "Init ok\n");
	if (!get_map_path(game, argc, argv))
		return (free(game->map_path), ERROR);
	ft_printf(1, "Map path ok\n");
	if (!get_map(game))
		return (ERROR);
	ft_printf(1, "Map ok\n");
	ft_printf(1, "NO = %s\n", game->texture.north_texture);
	ft_printf(1, "SO = %s\n", game->texture.south_texture);
	ft_printf(1, "WE = %s\n", game->texture.east_texture);
	ft_printf(1, "EA = %s\n", game->texture.west_texture);
	ft_printf(1, "F = 0x%X\n", game->texture.floor_color);
	ft_printf(1, "C = 0x%X\n", game->texture.ceiling_color);
	return (TRUE);
}