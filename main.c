/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:14:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/27 15:15:05 by jdhallen         ###   ########.fr       */
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
	mlx_key_hook(game.window, keycode_value, &game);
	mlx_loop(game.session);
	return (close_window(&game), 0);
}
