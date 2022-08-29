/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:02:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/16 12:48:41 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pxl_sky(t_render *game, int width, int height)
{
	int				x;
	int				y;
	unsigned int	attributes;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			attributes = get_attribute_data(game->sky.buffer, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}

void	put_pxl_wall(t_render *game, int width, int height)
{
	int				x;
	int				y;
	unsigned int	attributes;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			attributes = get_attribute_data(game->wall.buffer, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}

void	put_pxl_player(t_render *game, int width, int height)
{
	int				x;
	int				y;
	unsigned int	attributes;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			attributes = get_attribute_data(game->player.buffer, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}

void	put_pxl_coin(t_render *game, int width, int height)
{
	int				x;
	int				y;
	unsigned int	attributes;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			attributes = get_attribute_data(game->coin, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}
