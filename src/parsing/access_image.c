/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:54:34 by codespace         #+#    #+#             */
/*   Updated: 2025/04/22 11:05:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_image_type(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->texture.wall_texture[i][j] != '\0')
	{
		if (game->texture.wall_texture[i][j] == '.'
			&& game->texture.wall_texture[i][j + 1] == 'x'
			&& game->texture.wall_texture[i][j + 2] == 'p'
			&& game->texture.wall_texture[i][j + 3] == 'm'
			&& game->texture.wall_texture[i][j + 4] == '\0')
			return (TRUE);
		j++;
	}
	return (ft_printf(2, "Error\nWall texture not xpm\n"), FALSE);
}

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
		if (check_image_type(game, i) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
