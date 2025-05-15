/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:26:20 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/03 19:26:22 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ft_copy(t_my_game *my_game, t_cub *parsing)
{
	my_game->parsing = parsing;
	my_game->map.data = parsing->data->map;
	my_game->floor_color = parsing->texture->f_color;
	my_game->ceiling_color = parsing->texture->c_color;
	my_game->textures.north = parsing->texture->no;
	my_game->textures.south = parsing->texture->so;
	my_game->textures.west = parsing->texture->we;
	my_game->textures.east = parsing->texture->ea;
}
