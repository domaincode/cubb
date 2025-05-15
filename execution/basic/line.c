/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:24:00 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 11:24:03 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_line2(t_my_game *game, float dx, float dy, int color)
{
	float	steps;
	float	xinc;
	float	yinc;
	int		i;

	i = 0;
	steps = fmax(fabs(dx), fabs(dy));
	xinc = dx / steps;
	yinc = dy / steps;
	dx = game->player.px;
	dy = game->player.py;
	while (i < steps)
	{
		my_pixel_put(game->map_img, dx, dy, color);
		dx += xinc;
		dy += yinc;
		i++;
	}
}

void	draw_line(t_my_game *game, int x_end, int y_end, int color)
{
	float	dx;
	float	dy;

	dx = x_end - game->player.px;
	dy = y_end - game->player.py;
	draw_line2(game, dx, dy, color);
}
