/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:58:32 by codespace         #+#    #+#             */
/*   Updated: 2025/03/26 16:31:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_char(t_game *game, int *i, int *j, int *player)
{
	if (game->map[*i][*j].type == VOID
		|| game->map[*i][*j].type == WALL
		|| game->map[*i][*j].type == ' ')
		return ((*j)++, TRUE);
	else if (game->map[*i][*j].type == NORTH
		|| game->map[*i][*j].type == SOUTH
		|| game->map[*i][*j].type == WEST
		|| game->map[*i][*j].type == EAST)
	{
		if (*player == FALSE)
			*player = TRUE;
		else
			return (ft_printf(2, "Error\nMultiple player\n"), ERROR);
	}
	else
		return (ft_printf(2, "Error\nInvalid Char in Map\n"), ERROR);
	(*j)++;
	return (TRUE);
}

int	check_map_char(t_game *game)
{
	int	player;
	int	i;
	int	j;

	i = 0;
	j = 0;
	player = FALSE;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j].type != '\0')
		{
			if (check_char(game, &i, &j, &player) == ERROR)
				return (ERROR);
		}
		i++;
	}
	if (player == FALSE)
		return (ft_printf(2, "Error\nNo player in Map\n"), ERROR);
	return (TRUE);
}
