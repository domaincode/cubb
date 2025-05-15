/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:10:00 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/02 13:10:03 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_pixel_put(t_img *image, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x > image->width || y > image->height)
		return ;
	offset = x * 4 + y * image->size_line;
	*(int *)(image->data + offset) = color;
}

int	get_pixel(t_img *image, int x, int y)
{
	int	offset;

	if (x < 0 || y < 0 || x > image->width || y > image->height)
		return (0);
	offset = x * 4 + y * image->size_line;
	return (*(int *)(image->data + offset));
}
