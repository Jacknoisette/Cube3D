/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:50:47 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 15:16:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	move_through_empty_line(t_game *game, char **line)
{
	*line = get_next_line(game->map_fd);
	while (check_empty_line(*line) == FALSE)
	{
		free(*line);
		*line = get_next_line(game->map_fd);
	}
	if (check_empty_line(*line) == ERROR)
		return (ft_printf(2, "Error\nEOF before map\n"),
			free(*line), ERROR);
	return (TRUE);
}

t_map	create_temp_map(char c)
{
	t_map	map_temp;

	map_temp.type = c;
	return (map_temp);
}

t_map	*create_line_map(char **line, int len_max)
{
	t_map	*map_line_temp;
	int 	i;

	map_line_temp = malloc((len_max + 1) * sizeof(t_map));
	if (map_line_temp == NULL)
		return (free(*line), NULL);
	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
	{
		map_line_temp[i] = create_temp_map((*line)[i]);
		i++;
	}
	while (i < len_max)
	{
		map_line_temp[i] = create_temp_map(' ');
		i++;
	}
	map_line_temp[i] = create_temp_map('\0');
	free(*line);
	return (map_line_temp);
}

int	create_global_map(t_game *game, int file_len, int len_max)
{
	t_map	**map_global_temp;
	char	*line;
	int		i;
	int		j;
	
	line = NULL;
	if (move_through_empty_line(game, &line) == ERROR)
		return (ERROR);
	j = skip_space(line, 0);
	if (line[j] != '1')
		return (ft_printf(2, "Error\nMap incorrect\n"), free(line), ERROR);
	i = 0;
	map_global_temp = malloc((file_len + 1) * sizeof(t_map *));
	if (!map_global_temp)
		return (ft_printf(2, "Error\nMemory allocation failed\n"), ERROR);
	while (check_empty_line(line) == TRUE)
	{
		map_global_temp[i] = create_line_map(&line, len_max);
		if (map_global_temp[i] == NULL)
			return (free_mappp(map_global_temp), ERROR);
		line = get_next_line(game->map_fd);
		i++;
	}
	return (map_global_temp[i] = NULL, game->map = map_global_temp, TRUE);
}

int	get_map_parsing(t_game *game)
{
	int		temp_map_fd;
	int		file_len;
	int		len_max;
	
	file_len = 0;
	len_max = 0;
	temp_map_fd = open(game->map_path, O_RDONLY);
	if (move_in_file(game, temp_map_fd, &file_len, &len_max) == ERROR)
		return (close(temp_map_fd), ERROR);
	close(temp_map_fd);
	if (create_global_map(game, file_len, len_max) == ERROR)
		return (ERROR);
	return (TRUE);
}