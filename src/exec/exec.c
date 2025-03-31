/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:05:40 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/31 14:48:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

int	player_spawn_position(t_game *game)
{
	int	x;
	int	y;
	int	angle;

	if (find_player(game, &y, &x, &angle) == ERROR)
		return (ERROR);
	game->player.x = (float)x;
	game->player.y = (float)y;
	game->player.angle = (float)(90 * angle);
	printf("Int Player : X %i,Y %i,Z %i\n", x, y, 90 * angle);
	printf("Float Player : X %f,Y %f,Z %f\n", game->player.x, game->player.y, game->player.angle);
	return (TRUE);
}

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
	if (player_spawn_position(game) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	exec(t_game *game)
{
	player(game);
	if (rendering(game) == ERROR)
		return (ERROR);
	return (TRUE);
}
