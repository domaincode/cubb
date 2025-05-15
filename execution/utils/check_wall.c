/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:55:50 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 12:55:54 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	check_wall(t_my_game *game, int x, int y)
{
	int	rows;
	int	cols;

	rows = (y / TILE_SIZE);
	cols = (x / TILE_SIZE);
	if (rows >= 0 && cols >= 0 && cols < game->map.cols && rows < game->map.rows
		&& game->map.data[rows][cols] == '1')
		return (1);
	return (0);
}
