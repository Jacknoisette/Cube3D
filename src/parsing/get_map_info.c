/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/25 11:11:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (ERROR);
	while (line[i] != '\0' && line[i] != '\n' && ft_isalpha(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (ERROR);
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (ERROR);
	while (line[i] != '\0' && line[i] != '\n'
		&& ft_isprint(line[i]) && line[i] != ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (ft_isprint(line[i]))
			return (ERROR);
		i++;
	}
	return (TRUE);
}

int	create_data(t_game *game, char **data, int *info)
{
	char *line;
	
	line = get_next_line(game->map_fd);
	game->start_map_line++;
	while (check_empty_line(line) == FALSE)
	{
		free(line);
		line = get_next_line(game->map_fd);
		game->start_map_line++;
	}
	if (check_empty_line(line) == ERROR)
		return (ft_printf(2, "Error\nEOF before map\n"),
			free(line), ERROR);
	if (check_line(line) == ERROR)
		return (ft_printf(2, "Error\nWrong line in map\n"),
			free(line), ERROR);
	*info = get_info_texture(line);
	if (*info == ERROR)
		return (ft_printf(2, "Error\nMissing info\n"), free(line), ERROR);
	*data = ft_substr(line, get_start(line), get_len(line));
	if (*data == NULL)
		return (free(line), ERROR);
	return (free(line), TRUE);
}

int	get_map_info_color(t_game *game, char **data, int info)
{
	int	rgb_value;

	if (info == F || info == C)
	{
		rgb_value = get_rgb(*data);
		free(*data);
		if (rgb_value == ERROR)
			return (ERROR);
		if (info == F && game->texture.floor_color == 0)
			game->texture.floor_color = rgb_value;
		else if (info == F && game->texture.floor_color != 0)
			return (ft_printf(2, "Error\nBad info\n"), ERROR);
		if (info == C && game->texture.ceiling_color == 0)
			game->texture.ceiling_color = rgb_value;
		else if (info == C && game->texture.ceiling_color != 0)
			return (ft_printf(2, "Error\nBad info\n"), ERROR);
	}
	return (TRUE);
}

int	get_map_info(t_game *game)
{
	char	*data;
	int		info;
	int		all;

	all = 0;
	while (all < 6)
	{
		if (create_data(game, &data, &info) == ERROR)
			return (ERROR);
		if (info == NO || info == SO || info == WE || info == EA)
		{
			if (game->texture.wall_texture[info] == NULL)
				game->texture.wall_texture[info] = data;
			else
				return (ft_printf(2, "Error\nBad info\n"), free(data), ERROR);
		}
		if (get_map_info_color(game, &data, info) == ERROR)
			return (ERROR);
		all++;
	}
	return (TRUE);
}
