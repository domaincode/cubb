/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:50:47 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 11:50:51 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_map(t_my_game *game)
{
	int	colors;
	int	i;
	int	j;

	i = 0;
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (game->map.data[i][j] == '1')
				colors = color(0, 0, 0);
			else if (game->map.data[i][j])
				colors = color(255, 255, 255);
			draw_square(game->map_img, j * MAP_SIZE, i * MAP_SIZE, colors);
			j++;
		}
		i++;
	}
}

void	copy_minimap(t_my_game *game, int x_end, int y_end)
{
	int	x;
	int	x_map;
	int	y;
	int	y_map;
	int	colors;

	x = 0;
	y = 0;
	y_map = game->player.py - 40;
	while (y_map < y_end)
	{
		x_map = game->player.px - 60;
		x = 0;
		while (x_map < x_end)
		{
			colors = get_pixel(game->map_img, x_map, y_map);
			my_pixel_put(game->img, x, y, colors);
			x++;
			x_map++;
		}
		y_map++;
		y++;
	}
}

void	map_to_minimap(t_my_game *game, int px, int py)
{
	int	x_end;
	int	y_end;

	draw_map(game);
	draw_player(game->map_img, px, py, 255);
	x_end = round(px + 20 * cos(game->player.rot));
	y_end = round(py + 20 * sin(game->player.rot));
	draw_line(game, x_end, y_end, 255 << 16);
	x_end = px + 60;
	y_end = py + 40;
	copy_minimap(game, x_end, y_end);
}
