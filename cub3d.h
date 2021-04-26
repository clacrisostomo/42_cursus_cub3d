/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 01:45:00 by csantos-          #+#    #+#             */
/*   Updated: 2021/04/26 02:01:46 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/****
 * LIBRARIES
 ****/

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/includes/libft.h"

/****
 * KEYCODES
 ****/

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESS_MASK 1L<<0
# define KEYRELEASE_MASK 1L<<1
# define ESC 0x00ff1b
# define WIN_BUTTON_X 33 //NOTIFY MASK
# define WIN_BUTTON_X_MASK 1L<<17 //CLIENT_MESSAGE
# define MOUSE_1 1
# define W 0x0077
# define S 0x0073
# define D 0x0064
# define A 0x0061
# define UP 0x00ff52
# define DOWN 0x00ff54
# define RIGHT 0x00ff53
# define LEFT 0x00ff51
# define CLIENT_MESSAGE 33

/****
 * SCREEN DEFINITIONS
 ****/

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

/****
 * MAP DEFINITIONS
 ****/

# define NUM_ROWS 12
# define NUM_COLS 20
# define TILE_SIZE 64
# define NUM_RAYS SCREEN_WIDTH
# define MAP_SCALE 1
# define PI 3.14159265
# define TWO_PI 6.28316530

/****
 * STRUCTS
 ****/

typedef struct s_data
{
	int		*buff;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	double	radius;
	int		left_right;
	int		walk_direction;
	int		turn_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
}				t_player;

typedef struct s_ray
{
	double	angle;
	int		*dist_wall;
	double	wall_hitx;
	double	wall_hity;
	double	wall_dist;
	double	hit_vx;
	double	hit_vy;
	double	hit_hx;
	double	hit_hy;
	int		was_hit_v;
	double	interc_x;
	double	interc_y;
	int		face_up;
	int		face_dw;
	int		face_ri;
	int		face_le;
	double	x_step;
	double	y_step;
}				t_ray;
typedef struct s_map
{
	int	width;
	int	height;
	int	minimap;
}				t_map;

typedef struct s_colour
{
	int		red;
	int		green;
	int		blue;
}				t_colour;

typedef struct s_game
{
	double		fov;
	int			block;
	int			init;
	double		dist2player;
	t_data		data;
	t_player	player;
	t_map		map;
	t_colour	colour;
	t_ray		ray;
}				t_game;

/****
 * FUNCTIONS
 ****/

#endif