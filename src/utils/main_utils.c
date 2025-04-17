/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:14:17 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/01 15:22:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "../exec/exec.h"

int	keycode_value(int keycode, t_game *game)
{
	if (keycode == 119)
		return (move_key(game, W_KEY), 0);
	if (keycode == 115)
		return (move_key(game, S_KEY), 0);
	if (keycode == 97)
		return (move_key(game, A_KEY), 0);
	if (keycode == 100)
		return (move_key(game, D_KEY), 0);
	if (keycode == 65363)
		return (rotate_player(game, RIGHT_KEY), 0);
	if (keycode == 65361)
		return (rotate_player(game, LEFT_KEY), 0);
	if (keycode == 65307)
		return (close_window(game), 0);
	return (game->keycode = NULL_KEY, 0);
}

void	clean_game(t_game *game)
{
	int	i;

	if (game->map != NULL)
		free_mappp(&game->map);
	i = 0;
	while (i < 4)
	{
		if (game->texture.wall_texture[i])
			free(game->texture.wall_texture[i]);
		if (game->texture.wall_images[i])
			free_img(game->session, game->texture.wall_images[i]);
		i++;
	}
	if (game->map_path)
		free(game->map_path);
	if (game->map_fd != ERROR)
		close(game->map_fd);
	free_img(game->session, game->texture.ceiling_image);
	free_img(game->session, game->texture.floor_image);
	free_img(game->session, game->renderer);
}

int	close_window(t_game *game)
{
	mlx_clear_window(game->session, game->window);
	mlx_destroy_window(game->session, game->window);
	clean_game(game);
	mlx_destroy_display(game->session);
	free(game->session);
	exit(0);
}

int	create_ceilling_and_floor(t_game *game)
{
	create_image(game->texture.ceiling_image,
		WIDTH, HEIGHT / 2, game->texture.floor_color);
	create_image(game->texture.floor_image, WIDTH, HEIGHT / 2,
		game->texture.ceiling_color);
	mlx_put_image_to_window(game->session,
		game->window, game->texture.ceiling_image, 0, 0);
	mlx_put_image_to_window(game->session, game->window,
		game->texture.floor_image, 0, HEIGHT / 2);
	return (TRUE);
}
