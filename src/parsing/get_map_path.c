/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:12:09 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:16:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_file_type(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_path[i] != '\0')
	{
		if (game->map_path[i] == '.' && game->map_path[i + 1] == 'c'
			&& game->map_path[i + 2] == 'u' && game->map_path[i + 3] == 'b'
			&& game->map_path[i + 4] == '\0')
			return (TRUE);
		i++;
	}
	ft_printf(2, "Error\nMap not .cub\n");
	return (FALSE);
}

int	get_map_path(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf(2, "Error\nFile needed : <map_path.cub>\n"), FALSE);
	game->map_path = ft_strdup(argv[1]);
	if (!game->map_path)
		return (ft_printf(2, "Error\nMemory allocation failed\n"), FALSE);
	if (!check_file_type(game))
		return (free(game->map_path), FALSE);
	game->map_fd = open(game->map_path, O_RDONLY);
	if (game->map_fd == ERROR)
		return (free(game->map_path), FALSE);
	return (TRUE);
}
