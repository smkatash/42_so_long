/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:09:02 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/16 16:06:54 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	frame_update_sky(t_render *game)
{
	static int	frame;

	if (frame == 0)
		game->sky.buffer = game->sky.img1;
	if (frame == 60)
		game->sky.buffer = game->sky.img2;
	frame++;
	if (frame == 100)
		frame = 0;
	put_images(game);
	return (0);
}

static int	frame_update_wall(t_render *game)
{
	static int	frame;

	if (frame == 0)
		game->wall.buffer = game->wall.img1;
	if (frame == 60)
		game->wall.buffer = game->wall.img2;
	frame++;
	if (frame == 100)
		frame = 0;
	put_images(game);
	return (0);
}

static int	frame_update_player(t_render *game)
{
	static int	frame;

	if (frame == 0)
		game->player.buffer = game->player.img1;
	if (frame == 50)
		game->player.buffer = game->player.img2;
	frame++;
	if (frame == 100)
		frame = 0;
	put_images(game);
	return (0);
}

int	frame_loop(t_render *game)
{
	mlx_clear_window(game->mlx, game->window);
	frame_update_sky(game);
	frame_update_wall(game);
	frame_update_player(game);
	frame_update_enemy(game);
	return (0);
}
