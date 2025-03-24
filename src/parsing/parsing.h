/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:11:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:09:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_info_texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_info_texture;

// GET_MAP_PATH
int	get_map_path(t_game *game, int argc, char **argv);
int	check_file_type(t_game *game);

// GET_MAP
int	get_map(t_game *game);


//GET_MAP_INFO
int	get_map_info(t_game *game);
int get_info_texture(char *line);
int get_start(char *line);
int get_len(char *line);
int	get_rgb(char *data);
int ft_isws(char c);


#endif