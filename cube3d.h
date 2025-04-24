/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:13:39 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/23 10:46:36 by jdhallen         ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef WIDTH
#  define WIDTH 1080
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

//PLAYER

# define ROT_MAX 360

# define ROT_SPEED

typedef enum e_move
{
	NULL_KEY,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	LEFT_ARROW_KEY,
	RIGHT_ARROW_KEY,
	ESC_KEY,
}	t_move;

typedef enum e_info_texture
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	F,
	C,
}	t_info_texture;

//STRUCT

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	speed;
}	t_keys;

typedef struct s_ray
{
	int		*vision_x;
	int		*vision_y;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	float	wall_distance;
	int		ray;
	int		map_x;
	int		map_y;
	int		prev_map_x;
	int		prev_map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		n_texture;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_texture
{
	void	*ceiling_image;
	void	*floor_image;
	void	*wall_images[4];
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
	float	x;
	float	y;
	float	angle;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map		**map;
	t_texture	texture;
	t_keys		keys;
	void		*renderer;
	float		fov;
	char		*map_path;
	void		*session;
	void		*window;
	bool		error_in_walls;
	int			keycode;
	int			map_fd;
	int			start_map_line;
	int			max_width;
	int			max_height;
}	t_game;

//UTILS
void	clean_game(t_game *game);
int		close_window(t_game *game);
int		create_ceilling_and_floor(t_game *game);
int		find_player(t_game *game, int *pos_i, int *pos_j, float *dir);

//MAIN
int		keycode_value(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		parsing(t_game *game, int argc, char **argv);
int		exec(t_game *game);
int		exec_init(t_game *game);

#endif
