/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:24:11 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

void	display_info(t_game *game)
{
	int	i;
	int	j;

	ft_printf(1, "NO = %s\n", game->texture.wall_texture[NO]);
	ft_printf(1, "SO = %s\n", game->texture.wall_texture[SO]);
	ft_printf(1, "WE = %s\n", game->texture.wall_texture[WE]);
	ft_printf(1, "EA = %s\n", game->texture.wall_texture[EA]);
	ft_printf(1, "F = 0x%X\n", game->texture.floor_color);
	ft_printf(1, "C = 0x%X\n\n", game->texture.ceiling_color);
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j].type != '\0')
		{
			if (game->map[i][j].in_player_map)
				ft_printf(1, "\033[32m\033[1m");
			if (!game->map[i][j].in_player_map && game->map[i][j].type == VOID)
				ft_printf(1, "\033[34m");
			ft_printf(1, "%c\033[0m", game->map[i][j].type);
			j++;
		}
		ft_printf(1, "\n");
		i++;
	}
}

int	get_map(t_game *game)
{
	if (get_map_info(game) == ERROR)
		return (FALSE);
	if (get_map_parsing(game) == ERROR)
		return (FALSE);
	if (check_map(game, 0) == ERROR)
		return (FALSE);
	display_info(game);
	ft_printf(1, "\n");
	return (TRUE);
}
