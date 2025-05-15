/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:55:41 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 17:55:43 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	cub_confg(t_my_game *game)
{
	int	i;

	game->img = mlx_new_image(game->co, WIDTH, HEIGHT);
	game->map_img = mlx_new_image(game->co, game->map.cols * MAP_SIZE,
			game->map.rows * MAP_SIZE);
	game->north = mlx_xpm_file_to_image(game->co, game->textures.north, &i, &i);
	game->south = mlx_xpm_file_to_image(game->co, game->textures.south, &i, &i);
	game->west = mlx_xpm_file_to_image(game->co, game->textures.west, &i, &i);
	game->east = mlx_xpm_file_to_image(game->co, game->textures.east, &i, &i);
	if (!game->north || !game->south | !game->west || !game->east || !game->img ||
		!game->map_img)
		return (1);
	return (0);
}

int	cub_init(t_my_game *game)
{
	set_player_position(game);
	map_configuration(game, game->map.data);
	game->player.fov = 60 * (PI / 180);
	game->player.ray_angle_start = game->player.rot - (game->player.fov / 2);
	game->player.fix = TILE_SIZE * (WIDTH / (2 * tan(game->player.fov / 2)));
	game->player.rays = WIDTH / RES;
	game->forward_steps = 0;
	game->rotation = 0;
	game->right_steps = 0;
	game->co = mlx_init();
	if (game->co == NULL)
		return (1);
	game->win = mlx_new_window(game->co, WIDTH, HEIGHT, "cub3D");
	if (game->win == NULL || cub_confg(game) == 1)
	{
		mlx_destroy_display(game->co);
		free(game->co);
		return (1);
	}
	return (0);
}
