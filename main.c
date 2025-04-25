/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:14:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/23 10:31:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (parsing(&game, argc, argv) == ERROR)
		return (clean_game(&game), ERROR);
	game.session = mlx_init();
	if (game.session == NULL)
		return (ft_printf(2, "Error\nGame init\n"), ERROR);
	game.window = mlx_new_window(game.session, WIDTH, HEIGHT, "Cube3D");
	if (game.window == NULL)
		return (ft_printf(2, "Error\nWindow init\n", 1), ERROR);
	if (exec_init(&game) == ERROR)
		return (clean_game(&game), ERROR);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_loop_hook(game.session, exec, &game);
	mlx_hook(game.window, 2, (1L << 0), keycode_value, &game);
	mlx_hook(game.window, 3, (1L << 1), key_release, &game);
	mlx_loop(game.session);
	return (close_window(&game), 0);
}
