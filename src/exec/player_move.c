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

int	is_wall(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x].type == WALL)
		return 0;
	else
		return 1;
}

void	move_key(t_game *game, int input)
{
	float	new_x;
	float	new_y;
	
	new_x = game->player.x;
	new_y = game->player.y;
	if (input == W_KEY)
	{
		printf("W key pressed\n");
		new_x += cos(game->player.angle) * 0.1;
		new_y += sin(game->player.angle) * 0.1;
	}
	else if (input == A_KEY)
	{
		printf("A key pressed\n");
		new_x += cos(game->player.angle - (M_PI / 2) ) * 0.1;
		new_y += sin(game->player.angle - (M_PI / 2) ) * 0.1;
	}
	else if (input == S_KEY)
	{
		printf("S key pressed\n");
		new_x -= cos(game->player.angle) * 0.1;
		new_y -= sin(game->player.angle) * 0.1;
	}
	else if (input == D_KEY)
	{
		printf("D key pressed\n");
		new_x += cos(game->player.angle + (M_PI / 2) ) * 0.1;
		new_y += sin(game->player.angle + (M_PI / 2) ) * 0.1;
	}
	if (!is_wall(game,(int)new_x, (int)new_y))
		return ;
	game->player.x = new_x;
	game->player.y = new_y;
	printf("type: %c \n", game->map[(int)new_y][(int)new_x].type);
	//if(!is_wall(game, new_x, new_y))
	//{
	//	game->player.x = new_x;
	//	game->player.y = new_y;
	//}
}

void	rotate_player(t_game *game, int input)
{
	float angle;
	angle = game->player.angle;
	if (input == LEFT_KEY)
	{
		printf("Left key presssed\n");
		game->player.angle += -0.05 ;
		printf("angle: %f\n", game->player.angle);
	}
	else if (input == RIGHT_KEY)
	{
		printf("Right key pressed\n");
		game->player.angle += 0.05;
		printf("angle: %f\n", game->player.angle);
	}
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	else if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
