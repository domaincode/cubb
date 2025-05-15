/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_confg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:13:16 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 13:13:21 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	map_configuration(t_my_game *game, char **data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	while (data[y] != NULL)
	{
		x = ft_strlen(data[y]);
		if (game->map.cols < x)
			game->map.cols = x;
		y++;
	}
	game->map.rows = y;
	game->map.x_max = game->map.cols * TILE_SIZE;
	game->map.y_max = game->map.rows * TILE_SIZE;
}
