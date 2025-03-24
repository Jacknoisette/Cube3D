/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:16:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (ERROR);
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (FALSE);
	if (line[i] == '\0')
		return (ERROR);
	return (TRUE);
}

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
	while (check_empty_line(line) == FALSE)
	{
		free(line);
		line = get_next_line(game->map_fd);
	}
	if (check_empty_line(line) == ERROR)
		return (ft_printf(2, "Error\nEOF before map\n"),
			free(line), ERROR);
	if (check_line(line) == ERROR)
		return (ft_printf(2, "Error\nWrong line in map\n"),
			free(line), ERROR);
	*info = get_info_texture(line);
	if (*info == ERROR)
		return (ft_printf(1, "Error\nMissing information\n"), free(line), ERROR);
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
		if (info == C && game->texture.ceiling_color == 0)
			game->texture.ceiling_color = rgb_value;
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
		if (info == NO && game->texture.north_texture == NULL)
			game->texture.north_texture = data;
		if (info == SO && game->texture.south_texture == NULL)
			game->texture.south_texture = data;
		if (info == WE && game->texture.west_texture == NULL)
			game->texture.west_texture = data;
		if (info == EA && game->texture.east_texture == NULL)
			game->texture.east_texture = data;
		if (get_map_info_color(game, &data, info) == ERROR)
			return (ERROR);
		all++;
	}
	return (TRUE);
}
