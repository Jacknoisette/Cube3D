/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:54:34 by codespace         #+#    #+#             */
/*   Updated: 2025/03/26 16:11:13 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	access_image(t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 4)
	{
		fd = open(game->texture.wall_texture[i], O_RDONLY);
		if (fd == -1)
			return (ft_printf(2, "Error\nWall texture not found\n"), FALSE);
		close(fd);
		i++;
	}
	return (TRUE);
}
