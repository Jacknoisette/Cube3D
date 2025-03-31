/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:09:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/31 15:07:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

int	player_move(t_game *game)
{
	if (game->keycode == W_KEY)
		game->player.y -= 0.1;
	else if (game->keycode == S_KEY)
		game->player.y += 0.1;
	else if (game->keycode == A_KEY)
		game->player.x -= 0.1;
	else if (game->keycode == D_KEY)
		game->player.x += 0.1;
	else if (game->keycode == LEFT_ARROW_KEY)
		game->player.angle -= 0.1;
	else if (game->keycode == RIGHT_ARROW_KEY)
		game->player.angle += 0.1;
	return (TRUE);
}

int	player(t_game *game)
{
	player_move(game);
	return (TRUE);
}
