/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:15:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:09:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	get_map(t_game *game)
{
	if (get_map_info(game) == ERROR)
		return (FALSE);
	return (TRUE);
}