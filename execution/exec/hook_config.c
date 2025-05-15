/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:12:04 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/03 18:12:06 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	game_key_hook_confg1(t_my_game *game, int x, int y)
{
	if (!check_wall(game, x, game->player.py))
		game->player.px = (x);
	if (!check_wall(game, game->player.px, y))
		game->player.py = (y);
}

void	game_key_hook_confg(t_my_game *game, double f_steps, double r_steps,
		double rot)
{
	double	angle;
	double	x;
	double	y;

	game->player.rot = normalize_angle(game->player.rot + rot * (PI / 180));
	game->player.ray_angle_start = normalize_angle(game->player.rot
			- (game->player.fov / 2));
	if (r_steps)
	{
		angle = normalize_angle(game->player.rot + (PI / 2));
		x = round(game->player.px + r_steps * cos(angle));
		y = round(game->player.py + r_steps * sin(angle));
		game_key_hook_confg1(game, x, y);
		return ;
	}
	if(f_steps)
	{
		x = round(game->player.px + f_steps * cos(game->player.rot));
		y = round(game->player.py + f_steps * sin(game->player.rot));
		game_key_hook_confg1(game, x, y);
		return ;
	}
	//game_key_hook_confg1(game, x, y);
}
