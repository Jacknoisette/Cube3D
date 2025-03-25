/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:11:01 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 14:04:40 by codespace        ###   ########.fr       */
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

//Check_empty_line
//TRUE -> the line is not empty
//FALSE -> the line is empty and end by \n
//ERROR -> the line is empty and end by EOF
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

int	move_in_line(int temp_map_fd, int *file_len, int *len_max)
{
	char	*line;
	int		len;
	
	line = get_next_line(temp_map_fd);
	while (check_empty_line(line) == TRUE)
	{
		(*file_len)++;
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
