/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:31:40 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 18:31:45 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
#include "../parsing/parsing.h"

# define HEIGHT 800
# define WIDTH 800
# define PLAYER_SIZE 8
# define MAP_SIZE 32
# define TILE_SIZE 32
# define PI 3.14159265
# define RES 1

typedef struct s_text
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_text;

typedef struct s_my_map
{
	char		**data;
	int			rows;
	int			cols;
	int			y_max;
	int			x_max;

}				t_my_map;

typedef struct s_player
{
	int			px;
	int			py;
	double		fix;
	double		fov;
	double		rot;
	double		ray_angle_start;
	double		ray_angle;
	int			rays;
}				t_player;

typedef struct s_my_game
{
	t_cub		*parsing;
	t_xvar		*co;
	t_win_list	*win;
	t_player	player;
	t_my_map	map;
	t_text		textures;

	int			floor_color;
	int			ceiling_color;

	t_img		*img;
	t_img		*map_img;
	t_img		*test;

	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;

	//test
	double		forward_steps;
	double		right_steps;
	double		rotation;
}				t_my_game;

void			map_to_minimap(t_my_game *game, int px, int py);
void			draw_line(t_my_game *game, int x_end, int y_end, int color);
void			draw_square(t_img *image, int posx, int posy, int color);
void			draw_player(t_img *image, int posx, int posy, int color);

void			map_configuration(t_my_game *game, char **data);
double			normalize_angle(double angle);

int				free_game(t_my_game *game);
int				color(int r, int g, int b);
int				get_pixel(t_img *image, int x, int y);
void			my_pixel_put(t_img *image, int x, int y, int color);
void			set_player_position(t_my_game *game);
int				check_wall(t_my_game *game, int x, int y);
void			map_configuration(t_my_game *game, char **data);

int				cub_init(t_my_game *game);
void			check_intersections(t_my_game *game);
double			check_horizontal(t_my_game *game, double distance_to_wall,
					int *texture_x, int *indice);
double			check_vertical(t_my_game *game, double distance_to_wall,
					int *texture_x, int *indice);

void			ft_textures(t_my_game *game, int x_start, int texture_x,
					double projected_height);
void			ft_execution(t_my_game *game, t_cub *parsing);
void			game_key_hook_confg(t_my_game *game, double f_steps,
					double r_steps, double rot);
void	ft_copy(t_my_game *my_game, t_cub *parsing);
//void 			free_parsing(t_map *map);

#endif
