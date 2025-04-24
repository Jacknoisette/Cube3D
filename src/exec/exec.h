/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:06:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/23 10:35:42 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct s_texture_display
{
	float	wall_x;
	float	step;
	float	texture_pos;
	int		texture_offset;
	int		pixel_offset;
	int		y;
	int		texture_x;
	int		texture_y;
	int		color;
}	t_texture_display;

//EXEC
int		exec_init(t_game *game);
int		exec(t_game *game);
int		rendering(t_game *game);

//PLAYER_MOVEMENT
void	move_key(t_game *game);
void	rotate_player(t_game *game);
// int		player_move(t_game *game);

//COMPUTE RENDERER
int		compute_direction(t_game *game, t_ray *ray);
int		compute_distance(t_game *game, t_ray *ray);
int		compute_dda(t_game *game, t_ray *ray);
int		compute_wall_distance(t_game *game, t_ray *ray);
int		compute_line_to_draw(t_game *game, t_ray *ray);

//DISPLAY
void	draw_vertical_line_img(void *img_ptr, t_ray *ray, t_game *game);

#endif
