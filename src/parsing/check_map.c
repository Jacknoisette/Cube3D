/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:16:15 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 15:04:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_map(t_game *game)
{
	if (check_map_char(game) == ERROR)
		return (ERROR);
	if (check_map_wall(game) == ERROR)
		return (ERROR);
    return (TRUE);
}