/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:09:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/01 15:27:47 by jdhallen         ###   ########.fr       */
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

static void	update_move(int input, t_game *game, float *new_x, float *new_y)
{
	if (input == W_KEY)
	{
		*new_x += cos(game->player.angle) * 0.2;
		*new_y += sin(game->player.angle) * 0.2;
	}
	else if (input == A_KEY)
	{
		*new_x += cos(game->player.angle - (M_PI / 2)) * 0.2;
		*new_y += sin(game->player.angle - (M_PI / 2)) * 0.2;
	}
	else if (input == S_KEY)
	{
		*new_x -= cos(game->player.angle) * 0.2;
		*new_y -= sin(game->player.angle) * 0.2;
	}
	else if (input == D_KEY)
	{
		*new_x += cos(game->player.angle + (M_PI / 2)) * 0.2;
		*new_y += sin(game->player.angle + (M_PI / 2)) * 0.2;
	}
}

void	move_key(t_game *game, int input)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	update_move(input, game, &new_x, &new_y);
	if (!is_wall(game, (int)new_x, (int)game->player.y))
		game->player.x = new_x;
	if (!is_wall(game, (int)game->player.x, (int)new_y))
		game->player.y = new_y;
}

void	rotate_player(t_game *game, int input)
{
	if (input == LEFT_KEY)
		game->player.angle += -0.1 ;
	else if (input == RIGHT_KEY)
		game->player.angle += 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	else if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
