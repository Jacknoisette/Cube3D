/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:09:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/23 13:33:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

int	is_wall(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x].type == WALL)
		return (1);
	else
		return (0);
}

static void	update_move(t_game *game, float *new_x, float *new_y)
{
	float	speed;

	speed = 0.05 * (1 + game->keys.speed);
	if (game->keys.w == 1)
	{
		*new_x += cos(game->player.angle) * speed;
		*new_y += sin(game->player.angle) * speed;
	}
	if (game->keys.a == 1)
	{
		*new_x += cos(game->player.angle - (M_PI / 2)) * speed;
		*new_y += sin(game->player.angle - (M_PI / 2)) * speed;
	}
	if (game->keys.s == 1)
	{
		*new_x -= cos(game->player.angle) * speed;
		*new_y -= sin(game->player.angle) * speed;
	}
	if (game->keys.d == 1)
	{
		*new_x += cos(game->player.angle + (M_PI / 2)) * speed;
		*new_y += sin(game->player.angle + (M_PI / 2)) * speed;
	}
}

void	move_key(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	update_move(game, &new_x, &new_y);
	if (!is_wall(game, (int)new_x, (int)game->player.y))
		game->player.x = new_x;
	if (!is_wall(game, (int)game->player.x, (int)new_y))
		game->player.y = new_y;
}

void	rotate_player(t_game *game)
{
	float	speed;

	speed = 0.025;
	if (game->keys.left == 1)
		game->player.angle -= speed;
	if (game->keys.right == 1)
		game->player.angle += speed;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	else if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
