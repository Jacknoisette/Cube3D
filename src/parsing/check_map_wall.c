/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:57:42 by codespace         #+#    #+#             */
/*   Updated: 2025/04/29 10:12:29 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	is_not_a_wall(int c)
{
	if (c == VOID)
		return (TRUE);
	if (c == NORTH)
		return (TRUE);
	if (c == SOUTH)
		return (TRUE);
	if (c == WEST)
		return (TRUE);
	if (c == EAST)
		return (TRUE);
	return (FALSE);
}

// In order
// UPPER
// UPPER LEFT
// UPPER RIGHT
// DOWN
// DOWN LEFT
// DOWN RIGHT
// LEFT
// RIGHT
int	check_around_space(t_game *game, int i, int j)
{
	if (i > 0
		&& is_not_a_wall(game->map[i - 1][j].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (i > 0 && j > 0
		&& is_not_a_wall(game->map[i - 1][j - 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (i > 0 && game->map[i][j + 1].type != '\0'
		&& is_not_a_wall(game->map[i - 1][j + 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (game->map[i + 1] != NULL
		&& is_not_a_wall(game->map[i + 1][j].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (game->map[i + 1] != NULL && j > 0
		&& is_not_a_wall(game->map[i + 1][j - 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (game->map[i + 1] != NULL && game->map[i][j + 1].type != '\0'
		&& is_not_a_wall(game->map[i + 1][j + 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (j > 0
		&& is_not_a_wall(game->map[i][j - 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	if (game->map[i][j + 1].type != '\0'
		&& is_not_a_wall(game->map[i][j + 1].type))
		return (ft_printf(2, "Error\nInvalid Wall x[%i],y[%i]\n", i, j), ERROR);
	return (TRUE);
}

int	check_map_wall_verify(t_game *game, int i, int j)
{
	if (i == 0 || game->map[i + 1] == NULL)
		if (game->map[i][j].type != WALL
			&& game->map[i][j].type != ' ')
			return (ERROR);
	if (j == 0 || game->map[i][j + 1].type == '\0')
		if (game->map[i][j].type != WALL
		&& game->map[i][j].type != ' ')
			return (ERROR);
	if (game->map[i][j].type == ' '
		&& check_around_space(game, i, j) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	check_map_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j].type != '\0')
		{
			if (check_map_wall_verify(game, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (TRUE);
}
