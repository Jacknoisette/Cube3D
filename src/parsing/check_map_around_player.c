/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_around_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:31:57 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:35:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_void_around_player_verify(t_game *game, int k, int l)
{
	if (game->map[k][l].type == '\0')
		return (game->error_in_walls = true, ERROR);
	if (game->map[k][l].type == VOID
		&& !game->map[k][l].in_player_map)
		check_void_around_player(game, k, l);
	if (game->map[k][l].type == ' ')
		return (game->error_in_walls = true, ERROR);
	return (TRUE);
}

int	check_void_around_player(t_game *game, int i, int j)
{
	int	k;
	int	l;

	if (game->map[i][j].in_player_map == true)
		return (TRUE);
	game->map[i][j].in_player_map = true;
	k = i - 1;
	if (k < 0)
		return (game->error_in_walls = true, ERROR);
	while (k <= i + 1)
	{
		if (game->map[k] == NULL)
			return (game->error_in_walls = true, ERROR);
		l = j - 1;
		if (l < 0)
			return (game->error_in_walls = true, ERROR);
		while (l <= j + 1)
		{
			if (check_void_around_player_verify(game, k, l) == ERROR)
				return (ERROR);
			l++;
		}
		k++;
	}
	return (TRUE);
}

int	check_map_around_player(t_game *game, int i, int j)
{
	check_void_around_player(game, i, j);
	if (game->error_in_walls == true)
		return (ft_printf(2, "Error\nInvalid Wall\n"), ERROR);
	return (TRUE);
}
