/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:11:01 by codespace         #+#    #+#             */
/*   Updated: 2025/03/26 16:16:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int	skip_space(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

// Check_empty_line
// TRUE -> the line is not empty
// FALSE -> the line is empty and end by \n
// ERROR -> the line is empty and end by EOF
int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (ERROR);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (FALSE);
	if (line[i] == '\0')
		return (ERROR);
	return (TRUE);
}

int	move_in_line(int temp_map_fd, int *file_len, int *len_max)
{
	char	*line;
	int		len;

	line = get_next_line(temp_map_fd);
	(*file_len)++;
	while (check_empty_line(line) == TRUE)
	{
		free(line);
		line = get_next_line(temp_map_fd);
		if (line != NULL)
		{
			len = 0;
			while (line[len] != '\n' && line[len] != '\0')
				len++;
			if (len > *len_max)
				*len_max = len;
		}
		(*file_len)++;
	}
	free(line);
	return (TRUE);
}

int	move_in_file(t_game *game, int temp_map_fd, int *file_len, int *len_max)
{
	char	*line;
	int		i;

	i = 0;
	while (i < game->start_map_line)
	{
		line = get_next_line(temp_map_fd);
		free(line);
		i++;
	}
	line = get_next_line(temp_map_fd);
	while (check_empty_line(line) == FALSE)
	{
		free(line);
		line = get_next_line(temp_map_fd);
	}
	if (check_empty_line(line) == ERROR)
		return (ft_printf(2, "Error\nEOF before map\n"), free(line), ERROR);
	free(line);
	move_in_line(temp_map_fd, file_len, len_max);
	return (TRUE);
}

int	find_player(t_game *game, int *pos_i, int *pos_j, int *dir)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j].type != '\0')
		{
			if (game->map[i][j].type == NORTH)
				return (*pos_i = i, *pos_j = j, *dir = NO, TRUE);
			if (game->map[i][j].type == SOUTH)
				return (*pos_i = i, *pos_j = j, *dir = SO, TRUE);
			if (game->map[i][j].type == WEST)
				return (*pos_i = i, *pos_j = j, *dir = WE, TRUE);
			if (game->map[i][j].type == EAST)
				return (*pos_i = i, *pos_j = j, *dir = EA, TRUE);
			j++;
		}
		i++;
	}
	return (ft_printf(2, "Error\nNo player found in Map\n"), ERROR);
}
