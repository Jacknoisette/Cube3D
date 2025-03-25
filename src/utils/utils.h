/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:59:13 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/25 12:39:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

#include "stdlib.h"

typedef struct s_map t_map;

//CLEANING
void	free_charpp(char **str);
void	free_mappp(t_map **map);

#endif