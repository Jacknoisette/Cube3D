/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_getter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:09 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:21:51 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"
#include "parsing.h"

int get_info_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (NO);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (SO);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (WE);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (EA);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		return (F);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (C);
	return (ERROR);
}

int get_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n' && ft_isalpha(line[i]))
		i++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] == ' ')
		i++;
	return (i);
}

int get_len(char *line)
{
	int	i;
	int	start;

	start = get_start(line);
	i = start;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i - start);
}

int	check_rgb(char **color_group, int *rgb)
{
	int		color;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color_group[i] == NULL)
			return (ft_printf(2, "Error\nWrong Color\n"), ERROR);
		rgb[i] = atoi(color_group[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_printf(2, "Error\nWrong Color\n"), ERROR);
		i++;
	}
	if (color_group[i] != NULL)
		return (ft_printf(2, "Error\nWrong Color\n"), ERROR);
	color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (color);
}

int	get_rgb(char *data)
{
	char	**color_group;
	int		rgb[3];
	int		color;
	int		split_nbr;
	int		i;

	i = 0;
	split_nbr = 0;
	while (data[i] != '\0')
	{
		if (data[i] == ',')
			split_nbr++;
		i++;
	}
	if (split_nbr != 2)
		return (ft_printf(2, "Error\nWrong Color\n"), ERROR);
	color_group = ft_split(data, ',');
	if (color_group == NULL)
		return (ERROR);
	color = check_rgb(color_group, rgb);
	free_charpp(color_group);
	return (color);
}
