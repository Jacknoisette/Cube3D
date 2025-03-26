/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:05:40 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:11:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

int	exec_init(t_game *game)
{
	game->texture.wall_images = NULL;
	game->texture.ceiling_image = mlx_new_image(game->session, WIDTH, HEIGHT);
	if (game->texture.ceiling_image == NULL)
		return (ERROR);
	game->texture.floor_image = mlx_new_image(game->session, WIDTH, HEIGHT);
	if (game->texture.floor_image == NULL)
		return (ERROR);
	if (create_ceilling_and_floor(game) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	exec(t_game *game)
{
	player_move(game);
	return (TRUE);
}
