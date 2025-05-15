/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:20:49 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 14:20:52 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	choose_texture(t_my_game *game, int indice)
{
	if (indice == 1)
	{
		if (game->player.ray_angle >= 0 && game->player.ray_angle <= PI)
			game->test = game->south;
		else
			game->test = game->north;
	}
	else
	{
		if (game->player.ray_angle >= (PI / 2) && game->player.ray_angle <= (3
				* PI / 2))
			game->test = game->west;
		else
			game->test = game->east;
	}
}

void	check_intersections(t_my_game *game)
{
	double	distance;
	double	angle_increment;
	int		texture_x;
	int		indice;
	int		i;

	i = 0;
	texture_x = 0;
	distance = -1;
	angle_increment = game->player.fov / game->player.rays;
	game->player.ray_angle = game->player.ray_angle_start;
	//printf("rays:%d\n", game->player.rays);
	while (i < game->player.rays)
	{
		distance = check_horizontal(game, distance, &texture_x, &indice);
		distance = check_vertical(game, distance, &texture_x, &indice);
		choose_texture(game, indice);
		ft_textures(game, i * RES, texture_x, game->player.fix / distance);
		game->player.ray_angle = normalize_angle(game->player.ray_angle
				+ angle_increment);
		i++;
	}
}
