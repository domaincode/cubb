/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:11:42 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 13:11:44 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	set_player_position1(t_my_game *game, int x, int y)
{
	game->player.px = x * TILE_SIZE + 0.5 * TILE_SIZE;
	game->player.py = y * TILE_SIZE + 0.5 * TILE_SIZE;
	if (game->map.data[y][x] == 'N')
		game->player.rot = 270 * (PI / 180);
	else if (game->map.data[y][x] == 'S')
		game->player.rot = 90 * (PI / 180);
	else if (game->map.data[y][x] == 'W')
		game->player.rot = 180 * (PI / 180);
	else if (game->map.data[y][x] == 'E')
		game->player.rot = 360 * (PI / 180);
}

void	set_player_position(t_my_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.data[y])
	{
		x = 0;
		while (game->map.data[y][x])
		{
			if (game->map.data[y][x] != '0' && game->map.data[y][x] != '1' && game->map.data[y][x] != ' ')
			{
				set_player_position1(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}
