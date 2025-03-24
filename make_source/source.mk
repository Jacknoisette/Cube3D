# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:20:43 by jdhallen          #+#    #+#              #
#    Updated: 2025/03/24 16:03:22 by jdhallen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make_source/parsing_source.mk
include make_source/exec_source.mk
include make_source/utils_source.mk

vpath %.c $(PARS_DIR) $(EXEC_DIR) $(UTILS_DIR)