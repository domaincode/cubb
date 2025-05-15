/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:50:18 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 12:50:24 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_square(t_img *image, int posx, int posy, int color)
{
	int	i;
	int	j;

	i = posy;
	while (i < posy + MAP_SIZE)
	{
		j = posx;
		while (j < posx + MAP_SIZE)
		{
			my_pixel_put(image, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_img *image, int posx, int posy, int color)
{
	int	i;
	int	j;

	i = posy;
	while (i < posy + PLAYER_SIZE)
	{
		j = posx;
		while (j < posx + PLAYER_SIZE)
		{
			my_pixel_put(image, j, i, color);
			j++;
		}
		i++;
	}
}
