/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:27:13 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 16:27:15 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	facing_up(t_my_game *game, double *ay, double *YA, double ray_angle)
{
	if (sin(ray_angle) < 0)
	{
		*YA = -TILE_SIZE;
		*ay = (game->player.py / TILE_SIZE) * TILE_SIZE - 0.001;
	}
	else
	{
		*YA = TILE_SIZE;
		*ay = (game->player.py / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
}

double	check_horizontal(t_my_game *game, double distance_to_wall,
		int *texture_x, int *indice)
{
	double	ax;
	double	ay;
	double	ya;

	distance_to_wall = -1;
	facing_up(game, &ay, &ya, game->player.ray_angle);
	ax = ((ay - game->player.py) / tan(game->player.ray_angle))
		+ game->player.px;
	while (ax >= 0 && ay >= 0 && ay < game->map.y_max && ax < game->map.x_max)
	{
		if (check_wall(game, ax, ay) == 1)
		{
			*indice = 1;
			*texture_x = (int)ax % TILE_SIZE;
			distance_to_wall = (ax - game->player.px) * cos(game->player.rot)
				+ (ay - game->player.py) * sin(game->player.rot);
			break ;
		}
		ax += ya / tan(game->player.ray_angle);
		ay += ya;
	}
	return (distance_to_wall);
}
