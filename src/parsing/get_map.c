/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/25 15:14:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	get_map(t_game *game)
{
	if (get_map_info(game) == ERROR)
		return (FALSE);
	ft_printf(1, "NO = %s\n", game->texture.wall_texture[NO]);
	ft_printf(1, "SO = %s\n", game->texture.wall_texture[SO]);
	ft_printf(1, "WE = %s\n", game->texture.wall_texture[WE]);
	ft_printf(1, "EA = %s\n", game->texture.wall_texture[EA]);
	ft_printf(1, "F = 0x%X\n", game->texture.floor_color);
	ft_printf(1, "C = 0x%X\n", game->texture.ceiling_color);
	if (get_map_parsing(game) == ERROR)
		return (FALSE);
	for (int i = 0; game->map[i] != NULL; i++)
	{
		for (int j = 0; game->map[i][j].type != '\0'; j++)
			ft_printf(1, "%c", game->map[i][j].type);
		ft_printf(1, "\n");
	}
	ft_printf(1, "Actually get_line is at line : %i\n", game->start_map_line);
	if (check_map(game) == ERROR)
		return (FALSE);
	return (TRUE);
}
