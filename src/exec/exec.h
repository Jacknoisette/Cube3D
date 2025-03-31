/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:06:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/31 15:35:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//EXEC
int	exec_init(t_game *game);
int	exec(t_game *game);
int	player(t_game *game);
int rendering(t_game *game);

//COMPUTE RENDERER
int	compute_direction(t_game *game, t_ray *ray);
int	compute_distance(t_game *game, t_ray *ray);
int	compute_dda(t_game *game, t_ray *ray);
int	compute_wall_distance(t_game *game, t_ray *ray);
int	compute_line_to_draw(t_game *game, t_ray *ray);

#endif