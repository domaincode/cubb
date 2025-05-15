/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:22:19 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 16:22:21 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	facing_left(t_my_game *game, double *ax, double *XA, double ray_angle)
{
	if (cos(ray_angle) <= 0)
	{
		*XA = -TILE_SIZE;
		*ax = (game->player.px / TILE_SIZE) * TILE_SIZE - 0.001;
	}
	else
	{
		*XA = TILE_SIZE;
		*ax = (game->player.px / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
}

double	check_vertical(t_my_game *game, double distance_to_wall, int *texture_x,
		int *indice)
{
	double	my_distance;
	double	ax;
	double	ay;
	double	xa;

	facing_left(game, &ax, &xa, game->player.ray_angle);
	ay = ((ax - game->player.px) * tan(game->player.ray_angle))
		+ game->player.py;
	while (ax >= 0 && ay >= 0 && ay < game->map.y_max && ax < game->map.x_max)
	{
		if (check_wall(game, ax, ay) == 1)
		{
			my_distance = (ax - game->player.px) * cos(game->player.rot) + (ay
					- game->player.py) * sin(game->player.rot);
			if (distance_to_wall == -1 || distance_to_wall > my_distance)
			{
				*indice = 2;
				*texture_x = (int)ay % TILE_SIZE;
				return (my_distance);
			}
		}
		ay += xa * tan(game->player.ray_angle);
		ax += xa;
	}
	return (distance_to_wall);
}
