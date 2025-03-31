/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:05:01 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/31 14:37:47 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	find_map_limit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j].type != '\0')
		j++;
	while (game->map[i] != NULL)
		i++;
	game->max_width = j;
	game->max_height = i;
	return (TRUE);
}
