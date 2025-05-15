/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:17:28 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 15:17:31 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	color_ceiling(t_my_game *game, int y_start, int y_end, int x_start)
{
	int	x;
	int	y;
	int	x_end;

	x_end = x_start + RES;
	y = y_start;
	while (y < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			my_pixel_put(game->img, x, y, game->ceiling_color);
			x++;
		}
		y++;
	}
}

void	color_floor(t_my_game *game, int y_start, int y_end, int x_start)
{
	int	x;
	int	y;
	int	x_end;

	x_end = x_start + RES;
	y = y_start;
	while (y < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			my_pixel_put(game->img, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

void	ft_textures_confg(double *offset_begin, double *offset_end,
		int projected_height)
{
	if (*offset_begin < 0)
		*offset_begin = 0;
	*offset_end = *offset_begin + projected_height;
	if (*offset_end > HEIGHT)
		*offset_end = HEIGHT;
}

void	ft_textures(t_my_game *game, int x_start, int texture_x,
		double projected_height)
{
	double	x;
	double	y_start;
	double	y_end;
	int		texture_y;
	int		texture_color;

	y_start = (HEIGHT / 2) - (projected_height / 2);
	ft_textures_confg(&y_start, &y_end, projected_height);
	color_ceiling(game, 0, y_start, x_start);
	while (y_start < y_end)
	{
		texture_y = (y_start + ((projected_height / 2) - (HEIGHT / 2)))
			* (TILE_SIZE / projected_height);
		x = x_start;
		while (x < x_start + RES)
		{
			texture_color = get_pixel(game->test, texture_x, texture_y);
			my_pixel_put(game->img, x, y_start, texture_color);
			x++;
		}
		y_start++;
	}
	color_floor(game, y_end, HEIGHT, x_start);
}
