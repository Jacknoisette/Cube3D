/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:09:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:12:05 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"



static void	move_key_handler(t_game *game, int input)
{
	if (input == W_KEY)
	{
		printf("W key pressed\n");
		game->player.y += -1;
	}
	else if (input == A_KEY)
	{
		printf("A key pressed\n");
		game->player.x += -1;
	}
	else if (input == S_KEY)
	{
		printf("S key pressed\n");
		game->player.y += 1;
	}
	else if (input == D_KEY)
	{
		printf("D key pressed\n");
		game->player.x += -1;
	}
	else if (input == LEFT_KEY)
	{
		printf("Left key presssed\n");
		game->player.angle += ;
	}
	else if (input == RIGHT_KEY)
	{
		printf("Right key pressed\n");
		game->player.angle += -1;
	}
}

int	player_move(t_game *game)
{
	(void)game;
	return (TRUE);
}
