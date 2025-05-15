/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:03:50 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 13:03:52 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	free_game(t_my_game *game)
{
	mlx_destroy_image(game->co, game->img);
	mlx_destroy_image(game->co, game->map_img);
	mlx_destroy_image(game->co, game->north);
	mlx_destroy_image(game->co, game->south);
	mlx_destroy_image(game->co, game->west);
	mlx_destroy_image(game->co, game->east);
	mlx_destroy_window(game->co, game->win);
	mlx_destroy_display(game->co);
	free(game->co);
	//free_parsing(game->direction);
	printf("Exit\n");
	destroy_all(game->parsing);
	return 0;
}
