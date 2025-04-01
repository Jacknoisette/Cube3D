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

//Ma fonction temporaire;
// int	player_move(t_game *game)
// {
// 	if (game->keycode == W_KEY)
// 		game->player.y -= 0.01;
// 	else if (game->keycode == S_KEY)
// 		game->player.y += 0.01;
// 	else if (game->keycode == A_KEY)
// 		game->player.x -= 0.01;
// 	else if (game->keycode == D_KEY)
// 		game->player.x += 0.01;
// 	else if (game->keycode == LEFT_ARROW_KEY)
// 		game->player.angle -= 0.005;
// 	else if (game->keycode == RIGHT_ARROW_KEY)
// 		game->player.angle += 0.005;
// 	return (TRUE);
// }

void	move_key(t_game *game, int input)
{
	if (input == W_KEY)
	{
		printf("W key pressed\n");
		game->player.y += -0.01;
	}
	else if (input == A_KEY)
	{
		printf("A key pressed\n");
		game->player.x += -0.01;
	}
	else if (input == S_KEY)
	{
		printf("S key pressed\n");
		game->player.y += 0.01;
	}
	else if (input == D_KEY)
	{
		printf("D key pressed\n");
		game->player.x += -0.01;
	}
	else if (input == LEFT_KEY)
	{
		printf("Left key presssed\n");
		game->player.angle += 0.005 ;
	}
	else if (input == RIGHT_KEY)
	{
		printf("Right key pressed\n");
		game->player.angle += -0.005;
	}
}
