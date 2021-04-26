/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 01:41:08 by csantos-          #+#    #+#             */
/*   Updated: 2021/04/26 04:01:57 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const int	map[NUM_ROWS][NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

/****
 * CONFIGURATION
 ****/

void	set_param(t_game *game)//TODO: INCLUDE OTHER SETTINGS
{
	ft_memset(game, 0, sizeof(t_game));
	game->fov = PI / 3;
	game->block = TILE_SIZE;
	game->ray.dist_wall = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
	game->player.radius = 5;
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	game->player.left_right = 0;
	game->player.walk_speed = 50;
	game->player.turn_speed = 1 * (PI / 180);
	game->player.x = (NUM_COLS * game->block / 2) * MAP_SCALE;
	game->player.y = (NUM_ROWS * game->block / 2) * MAP_SCALE;
	game->player.width = 3 * MAP_SCALE;
	game->player.height = 3 * MAP_SCALE;
	game->player.rotation_angle = PI / 2;
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->data.mlx, game->data.win);
	free(game->ray.dist_wall);
	exit(true);
	return (true);
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == W)
		game->player.walk_direction = -1;
	if (key == S)
		game->player.walk_direction = +1;
	if (key == A)
		game->player.left_right = -1;
	if (key == D)
		game->player.left_right = +1;
	if (key == RIGHT)
		game->player.turn_direction = +1;
	if (key == LEFT)
		game->player.turn_direction = -1;
	return (true);
}

int	release_key(int key, t_game *game)
{
	if (key == W || key == S)
		game->player.walk_direction = 0;
	if (key == A || key == D)
		game->player.left_right = 0;
	if (key == RIGHT || key == LEFT)
		game->player.turn_direction = 0;
	return (true);
}

/****
 * WALLS
 ****/

int	is_wall(t_game *game, int x, int y)
{
	int	block_size;
	int	x_map;
	int	y_map;

	block_size = game->block * MAP_SCALE;
	x_map = floor(x / block_size);
	y_map = floor(y / block_size);
	return (map[y_map][x_map]);
}

int	check_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;
	int	dist;
	int	result;

	x = new_x;
	y = new_y;
	dist = 3 * MAP_SCALE; //(game->block / 8);
	result = 0;
	if (is_wall(game, x - dist, y - dist) == 1
		|| is_wall(game, x - dist, y - dist) == '2')
		result = 1;
	if (is_wall(game, x + dist, y - dist) == 1
		|| is_wall(game, x + dist, y - dist) == '2')
		result = 1;
	if (is_wall(game, x - dist, y + dist) == 1
		|| is_wall(game, x - dist, y + dist) == '2')
		result = 1;
	if (is_wall(game, x + dist, y + dist) == 1
		|| is_wall(game, x + dist, y + dist) == '1')
		result = 1;
	return (result);
}

double	dist2points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	dist2wall(t_game *game, double horiz_dist, double vert_dist)
{
	game->ray.was_hit_v = 0;
	if (horiz_dist < vert_dist)
	{
		game->ray.wall_dist = horiz_dist;
		game->ray.wall_hitx = game->ray.hit_hx;
		game->ray.wall_hity = game->ray.hit_hy;
	}
	else
	{
		game->ray.wall_dist = vert_dist;
		game->ray.wall_hitx = game->ray.hit_vx;
		game->ray.wall_hity = game->ray.hit_vy;
	}
}

void	find_dist(t_game *game, int horiz_hit, int vert_hit)
{
	double	horiz_dist;
	double	vert_dist;

	if (horiz_hit)
		horiz_dist = dist2points(game->player.x, game->player.y,
				game->ray.hit_hx, game->ray.hit_hy);
	else
		horiz_dist = __INT_MAX__;
	if (vert_hit)
		vert_dist = dist2points(game->player.x, game->player.y,
				game->ray.hit_vx, game->ray.hit_vy);
	else
		vert_dist = __INT_MAX__;
	dist2wall(game, horiz_dist, vert_dist);
}

/****
 * HORIZONTAL CASTING
 ****/

void	check_horiz(t_game *game, int *horizhit)
{
	double	next_x;
	double	next_y;

	next_x = game->ray.interc_x;
	next_y = game->ray.interc_y;
	while (next_x >= 0 && next_x < (game->block * NUM_COLS)
		&& next_y >= 0 && next_y < (game->block * NUM_ROWS))
	{
		if (is_wall(game, next_x, (next_y - game->ray.face_up) == '1'))
		{
			*horizhit = 1;
			game->ray.hit_hx = next_x;
			game->ray.hit_hy = next_y;
			break ;
		}
		else
		{
			//if (is_wall(game, next_x, next_y - game->ray.face_up) == '2)
				//spritevisible(game, next_x, next_y - game->ray.face_up);
			next_x += game->ray.x_step;
			next_y += game->ray.y_step;
		}
	}
}

void	horiz_cast(t_game *game, int *horizhit)
{
	game->ray.interc_y = floor(game->player.y / game->block) * game->block;
	if (game->ray.face_dw)
		game->ray.interc_y += game->block;
	game->ray.interc_x = game->player.x
		+ (game->ray.interc_y - game->player.y) / tan(game->ray.angle);
	game->ray.y_step = game->block;
	if (game->ray.face_up)
		game->ray.y_step *= -1;
	game->ray.x_step = game->block / tan(game->ray.angle);
	if ((game->ray.face_le && game->ray.x_step > 0)
		|| (game->ray.face_ri && game->ray.x_step < 0))
		game->ray.x_step *= -1;
	//if (game->ray.face_ri && game->ray.x_step < 0)
		//game->ray.x_step *= -1;
	check_horiz(game, horizhit);
}

/****
 * VERTICAL CASTING
 ****/
//TODO: Check line 247 with Tucos (264 for them)

void	check_vert(t_game *game, int *verthit)
{
	double	next_x;
	double	next_y;

	next_x = game->ray.interc_x;
	next_y = game->ray.interc_y;
	while (next_x >= 0 && next_x < (game->block * NUM_COLS)
		&& next_y >= 0 && next_y < (game->block * NUM_ROWS))
	{
		if (is_wall(game, (next_x - game->ray.face_le), next_y) == '1')
		{
			*verthit = 1;
			game->ray.hit_vx = next_x;
			game->ray.hit_vy = next_y;
			break ;
		}
		else
		{
			//if (is_wall(game, next_x - game->ray.face.le, next_y) == '2')
				//spritevisible(game, next_x - game->ray.face_le, next_y);
			next_x = game->ray.x_step;
			next_y = game->ray.y_step;
		}
	}
}

void	vert_cast(t_game *game, int *verthit)
{
	game->ray.interc_x = floor(game->player.x / game->block) * game->block;
	if (game->ray.face_ri)
		game->ray.interc_x += game->block;
	game->ray.interc_y = game->player.y
		+ (game->ray.interc_x - game->player.x) / tan(game->ray.angle);
	game->ray.x_step = game->block;
	if (game->ray.face_le)
		game->ray.x_step *= -1;
	game->ray.y_step = game->block * tan(game->ray.angle);
	if ((game->ray.face_up && game->ray.y_step > 0)
		|| (game->ray.face_dw && game->ray.y_step < 0))
		game->ray.y_step *= -1;
	//if (game->ray.face_ri && game->ray.x_step < 0)
		//game->ray.x_step *= -1;
	check_vert(game, verthit);
}

/****
 * GRAPHICS
 ****/

void	put_image_pixel(t_game *game, int x, int y)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			*pixel;

	red = (unsigned char)game->colour.red;
	green = (unsigned char)game->colour.green;
	blue = (unsigned char)game->colour.blue;
	pixel = game->data.addr + (y * game->data.line_len + x
			* (game->data.bpp / 8));
	*(unsigned int*)pixel = (red << 16 | green << 8 | blue);
}

double	normalise_angle(double angle)
{
	double	norm_angle;

	norm_angle = remainder(angle, 2 * PI);
	if (norm_angle < 0)
		norm_angle = (2 * PI) + norm_angle;
	return (norm_angle);
}

void	ray_facing(t_game *game, double ray)
{
	if (ray > 0 && ray < PI)
		game->ray.face_dw = 1;
	if (!game->ray.face_dw)
		game->ray.face_up = 1;
	if (ray < 0.5 * PI || ray > 1.5 * PI)
		game->ray.face_ri = 1;
	if (!game->ray.face_ri)
		game->ray.face_le = 1;
}

void	oneraycast(t_game *game, double rayangle)
{
	int	horizhit;
	int	verthit;

	horizhit = 0;
	verthit = 0;
	game->ray.angle = normalise_angle(rayangle);
	ray_facing(game, game->ray.angle);
	horiz_cast(game, &horizhit);
	vert_cast(game, &verthit);
	game->ray.was_hit_v = 0;
	find_dist(game, horizhit, verthit);
}

void	castrays(t_game *game)
{
	int		width;
	double	rayangle;
	double	incstep;
	int		i;

	width = SCREEN_WIDTH;
	rayangle = normalise_angle(game->player.rotation_angle - PI / 6);
	incstep = PI / 3 / (double)width;
	i = 0;
	//find_sprite(game)//TODO:
	while (i < width)
	{
		rayangle = game->player.rotation_angle
			+ atan((i - (width / 2)) / game->dist2player);
		oneraycast(game, rayangle);
		game->ray.dist_wall[i] = game->ray.wall_dist;
		//renderprojectedwalls(game, i);//TODO:
		i++;
	}
	//sprite(game);//TODO:
}

void	draw_rect(t_game *game)
{
	int	i;
	int	j;

	i = game->map.width;
	while (i < game->map.width + (game->block * MAP_SCALE))
	{
		j = game->map.height;
		while (j < game->map.height + (game->block * MAP_SCALE))
		{
			put_image_pixel(game, i, j);
			j++;
		}
		i++;
	}
}

/****
 * PLAYER
 ****/

void	move_player(t_game *game)
{
	double	move_ws;
	double	move_ad;
	double	px;
	double	py;

	move_ws = game->player.walk_direction * game->player.walk_speed;
	move_ad = game->player.left_right * game->player.walk_speed;
	//game->player.rotationangle = normalise_angle(game->player.rotation_angle);
	game->player.rotation_angle += game->player.turn_direction
		* game->player.turn_speed;
	px = game->player.x + (cos(game->player.rotation_angle) * move_ws);
	py = game->player.y + (sin(game->player.rotation_angle) * move_ws);
	px = px + cos(game->player.rotation_angle - (90 * PI / 180)) * move_ad;
	py = py + sin(game->player.rotation_angle - (90 * PI / 180)) * move_ad;
	ray_facing(game, game->player.rotation_angle);
	if (check_wall(game, px, game->player.y) != 1)
		game->player.x = px;
	if (check_wall(game, game->player.x, py) != 1)
		game->player.y = py;
	castrays(game);
}

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	game->colour.red = 0;
	game->colour.green = 0;
	game->colour.blue = 0;
	i = game->player.x - 3;
	while (i < (game->player.x + game->player.width))
	{
		j = game->player.y - 3;
		while (j < (game->player.y + game->player.height))
		{
			//game->player.x = j * game->block + (game->block / 2);
			//game->player.y = i * game->block + (game->block / 2);
			//printf("valor i %d valor j %d\n", i, j);
			put_image_pixel(game, i, j);
			j++;
		}
		i++;
	}
}

/****
 * MAP
 ****/

void	minimap(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < NUM_ROWS)
	{
		col = 0;
		while (col < NUM_COLS)
		{
			game->map.width = (col * game->block) * MAP_SCALE;
			game->map.height = (row * game->block) * MAP_SCALE;
			if (map[row][col] != 0)
			{
				game->colour.red = 102;
				game->colour.green = 0;
				game->colour.blue = 204;
			}
			else
			{
				game->colour.red = 70;
				game->colour.green = 70;
				game->colour.blue = 70;
			}
			draw_rect(game);
			col++;
		}
		row++;
	}
}

//TODO: draw fov
/****
 * UPDATE
 ****/

int	update(t_game *game)
{
	if (game->init == 0)
	{
		minimap(game);
		draw_player(game);
		if (game->player.walk_direction || game->player.left_right
			|| game->player.turn_direction)
			castrays(game);
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img, 0, 0);
	}
	return (0);
}

/****
 * MAIN FUNCTION
 ****/
//TODO: ARGS/ERRORS

int	main(void)
{
	t_game	game;

	set_param(&game);
	game.data.mlx = mlx_init();
	if (game.init == 0)
		game.data.win = mlx_new_window(game.data.mlx, SCREEN_WIDTH,
				SCREEN_HEIGHT);
	if (game.init == 0)
		game.data.img = mlx_new_image(game.data.mlx, SCREEN_WIDTH,
				SCREEN_HEIGHT);
	game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bpp,
			&game.data.line_len, &game.data.endian);
	update(&game);
	if (game.init == 0)
	{
		mlx_hook(game.data.win, KEYPRESS, (1l << 0), press_key, &game);
		mlx_hook(game.data.win, KEYRELEASE, (1l << 1), release_key, &game);
		mlx_hook(game.data.win, WIN_BUTTON_X, (1l << 17), close_window, &game);
		mlx_loop_hook(game.data.mlx, update, &game);
		mlx_loop(game.data.mlx);
	}
	return (true);
}
