/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:11:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/25 16:02:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// GET_MAP_PATH
int	get_map_path(t_game *game, int argc, char **argv);
int	check_file_type(t_game *game);

// GET_MAP
int	get_map(t_game *game);
int	get_map_parsing(t_game *game);

//CHECK_MAP
int	check_map(t_game *game);
int	check_map_wall(t_game *game);
int	check_map_char(t_game *game);

//GET_MAP_INFO
int	get_map_info(t_game *game);
int get_info_texture(char *line);
int get_start(char *line);
int get_len(char *line);
int	get_rgb(char *data);

//ACCESS
int access_image(t_game *game);

//UTILS
int	check_empty_line(char *line);
int	move_in_file(t_game *game, int temp_map_fd, int *file_len, int *len_max);
int	skip_space(char *line, int i);


#endif