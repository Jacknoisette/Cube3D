/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:16:15 by codespace         #+#    #+#             */
/*   Updated: 2025/03/26 16:33:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

// 1 is to check the map around player
// 0 is to check all the map
int	check_map(t_game *game, int mod)
{
	int	i;
	int	j;
	int	dir;

	i = 0;
	j = 0;
	dir = 0;
	if (check_map_char(game) == ERROR)
		return (ERROR);
	ft_printf(1, "Char ok\n");
	if (mod)
	{
		if (find_player(game, &i, &j, &dir) == ERROR)
			return (ERROR);
		ft_printf(1, "Player ok\n");
		if (check_map_around_player(game, i, j) == ERROR)
			return (ERROR);
	}
	else
	{
		if (check_map_wall(game) == ERROR)
			return (ERROR);
	}
	ft_printf(1, "Wall ok\n");
	return (TRUE);
}
