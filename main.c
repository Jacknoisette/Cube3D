/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:14:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:25 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	close_window(t_game *game)
{
	mlx_clear_window(game->session, game->window);
	mlx_destroy_window(game->session, game->window);
	close(game->map_fd);
	free(game->session);
	exit(0);
}

int	keycode_value(int keycode, t_game *game)
{
	if (keycode == 119)
		return (game->keycode = W_KEY, 0);
	if (keycode == 115)
		return (game->keycode = S_KEY, 0);
	if (keycode == 97)
		return (game->keycode = A_KEY, 0);
	if (keycode == 100)
		return (game->keycode = D_KEY, 0);
	if (keycode == 65363)
		return (game->keycode = RIGHT_ARROW_KEY, 0);
	if (keycode == 65361)
		return (game->keycode = LEFT_ARROW_KEY, 0);
	if (keycode == 65307)
		return (close_window(game), 0);
	return (game->keycode = NULL_KEY, 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (parsing(&game, argc, argv) == ERROR)
		return (ERROR);
	game.session = mlx_init();
	if (game.session == NULL)
		return (ft_printf(2, "Error\nGame init\n"), ERROR);
	game.window = mlx_new_window(game.session, 1920, 1080, "Cube3D");
	if (game.window == NULL)
		return (ft_printf(2, "Error\nWindow init\n", 1), ERROR);
	mlx_hook(game.window, 17, 0, close_window, &game);
	// mlx_loop_hook(game.session, , &game);
	mlx_key_hook(game.window, keycode_value , &game);
	mlx_loop(game.session);
	return (close_window(&game), 0);
}
