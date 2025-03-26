/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:13:39 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/26 16:37:30 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "minilbx/mlx.h"
# include "Libft/ft_libft/ft_libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/get_next_line/get_next_line.h"
# include "src/utils/utils.h"
# include <stdbool.h>
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

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

//MAP

# ifndef WALL
#  define WALL '1'
# endif

# ifndef VOID
#  define VOID '0'
# endif

# ifndef NORTH
#  define NORTH 'N'
# endif

# ifndef SOUTH
#  define SOUTH 'S'
# endif

# ifndef WEST
#  define WEST 'W'
# endif

# ifndef EAST
#  define EAST 'E'
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

typedef enum e_info_texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_info_texture;

//STRUCT

typedef struct s_texture
{
	void	*ceiling_image;
	void	*floor_image;
	void	**wall_images;
	char	*wall_texture[4];
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_map
{
	char	type;
	bool	in_player_map;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map		**map;
	t_texture	texture;
	char		*map_path;
	void		*session;
	void		*window;
	bool		error_in_walls;
	int			keycode;
	int			map_fd;
	int			start_map_line;
}	t_game;

//UTILS
void	clean_game(t_game *game);
int		close_window(t_game *game);
int		create_ceilling_and_floor(t_game *game);

//MAIN
int		keycode_value(int keycode, t_game *game);
int		parsing(t_game *game, int argc, char **argv);
int		exec(t_game *game);
int		exec_init(t_game *game);

#endif