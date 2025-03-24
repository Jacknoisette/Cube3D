/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:13:39 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:22 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "minilbx/mlx.h"
# include "Libft/ft_libft/ft_libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/get_next_line/get_next_line.h"
# include "src/utils/utils.h"
# include <math.h>

//BASE

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

//CUBE3D

# ifndef SIZE
#  define SIZE 32
# endif

# ifndef FOV
#  define FOV 90
# endif

typedef enum e_move
{
	NULL_KEY,
	W_KEY,
	A_KEY,
	S_KEY,
	D_KEY,
	LEFT_ARROW_KEY,
	RIGHT_ARROW_KEY,
	ESC_KEY,
}	t_move;

//STRUCT

typedef struct s_texture
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_map
{
	char	type;
}	t_map;

typedef struct s_player
{
	double x;
	double y;
	double angle;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map		**map;
	t_texture	texture;
	char		*map_path;
	void		*session;
	void		*window;
	int			keycode;
	int			map_fd;
}	t_game;

int	parsing(t_game *game, int argc, char **argv);

#endif