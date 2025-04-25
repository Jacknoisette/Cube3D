/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:05:40 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/25 09:36:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "exec.h"

int	player_spawn_position(t_game *game)
{
	int		x;
	int		y;
	float	angle;

	if (find_player(game, &y, &x, &angle) == ERROR)
		return (ERROR);
	game->player.x = (float)x + 0.5;
	game->player.y = (float)y + 0.5;
	game->player.angle = (float)(angle);
	return (TRUE);
}

int	init_image(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = SIZE;
	height = SIZE;
	while (i < 4)
	{
		game->texture.wall_images[i] = mlx_xpm_file_to_image(game->session,
				game->texture.wall_texture[i],
				&width, &height);
		if (!game->texture.wall_images[i])
		{
			ft_printf(2, "Error\nImage can't open\n");
			return (ERROR);
		}
		i++;
	}
	return (TRUE);
}

int	exec_init(t_game *game)
{
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->keys.speed = 0;
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
	if (init_image(game) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	exec(t_game *game)
{
	move_key(game);
	rotate_player(game);
	if (rendering(game) == ERROR)
		return (ERROR);
	return (TRUE);
}
