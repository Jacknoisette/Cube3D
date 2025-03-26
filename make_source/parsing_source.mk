# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parsing_source.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:16:56 by jdhallen          #+#    #+#              #
#    Updated: 2025/03/26 16:34:57 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARS_DIR = src/parsing

SRCS_PARS = parsing.c \
	get_map.c get_map_path.c \
	get_map_info.c get_map_info_getter.c \
	get_map_parsing.c get_map_utils.c \
	check_map.c check_map_char.c check_map_wall.c \
	check_map_around_player.c \
	access_image.c
	
